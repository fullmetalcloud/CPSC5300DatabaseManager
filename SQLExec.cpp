//
// Created by Kevin Lundeen on 4/6/17.
//

#include "SQLExec.h"
Tables* SQLExec::tables = nullptr;

std::ostream &operator<<(std::ostream &out, const QueryResult &qres) {
    if (qres.column_names != nullptr) {
        for (auto const &column_name: *qres.column_names)
            out << column_name << " ";
        out << std::endl << "+";
        for (u_long i = 0; i < qres.column_names->size(); i++)
            out << "------------+";
        out << std::endl;
        for (auto const &row: *qres.rows) {
            for (auto const &column_name: *qres.column_names) {
                Value value = row->at(column_name);
                switch (value.data_type) {
                    case ColumnAttribute::INT:
                        out << value.n;
                        break;
                    case ColumnAttribute::TEXT:
                        out << "\"" << value.s << "\"";
                        break;
                    default:
                        out << "???";
                }
                out << " ";
            }
            out << std::endl;
        }
    }
    out << qres.message;
    return out;
}

QueryResult::~QueryResult() {

}
QueryResult *SQLExec::execute(const hsql::SQLStatement *statement) throw(SQLExecError) {
    try {
        if(SQLExec::tables==nullptr)
            SQLExec::tables = new Tables();
        switch (statement->type()) {
            case hsql::kStmtCreate:
                return create((const hsql::CreateStatement *) statement);
            case hsql::kStmtDrop:
                return drop((const hsql::DropStatement *) statement);
            case hsql::kStmtShow:
                return show((const hsql::ShowStatement *) statement);
            default:
                return new QueryResult("not implemented");
        }
    } catch (DbRelationError& e) {
        throw SQLExecError(std::string("DbRelationError: ") + e.what());
    }
}
QueryResult *SQLExec::create(const hsql::CreateStatement *statement) {
    if(statement->type!= hsql::CreateStatement::kTable)
        return new QueryResult("All but Table Not Implemented");
    ValueDict* insertRow = new ValueDict();
    Handle tableHandle;
    Handles colHandles;
    ColumnNames newColNames;
    ColumnAttributes newColAttributes;
    ColumnAttribute colAttribute;
    Columns& columnTable = (Columns&)  SQLExec::tables->get_table(Columns::TABLE_NAME);
    std::string tableName = statement->tableName;
    (*insertRow)["table_name"] = tableName;
    tableHandle = SQLExec::tables->insert(insertRow);
    try {
        std::map<Identifier,Value>::iterator it;
        for(auto const& column : *statement->columns) {
            (*insertRow)["column_name"] = Value(column->name);
            newColNames.push_back(column->name);
            if(column->type==hsql::ColumnDefinition::DataType::INT) {
                (*insertRow)["data_type"] = Value("INT");
                colAttribute.set_data_type(ColumnAttribute::INT);
            }
            else if(column->type==hsql::ColumnDefinition::DataType::TEXT) {
                (*insertRow)["data_type"] = Value("TEXT");
                colAttribute.set_data_type(ColumnAttribute::TEXT);
            }
            else
                throw DbRelationError("Type Not Implemented");
            colHandles.push_back(columnTable.insert(insertRow));
            newColAttributes.push_back(colAttribute);
        }
    } catch(DbRelationError& e) {
        for(auto const& colHandle:colHandles)
            columnTable.del(colHandle);
        SQLExec::tables->del(tableHandle);
        throw(e);
    }
    HeapTable newTable(tableName,newColNames,newColAttributes);
    newTable.create();
    return new QueryResult("created " + tableName);
}
QueryResult *SQLExec::drop(const hsql::DropStatement *statement) {
    if(statement->type!= hsql::DropStatement::EntityType::kTable)
        return new QueryResult("All but Table Not Implemented");
    std::string name = statement->name;
    try{
        HeapTable& table = (HeapTable&) SQLExec::tables->get_table(statement->name);
        table.drop();
    }catch(DbRelationError& e)
    {
        throw(e);
    }
    HeapTable& tablesTable = (HeapTable&) SQLExec::tables->get_table(Tables::TABLE_NAME);
    ValueDict tableName;
    tableName["table_name"] = Value(statement->name);
    Handles delTableHandle = *tablesTable.select(&tableName);
    for(auto const& deleteTable : delTableHandle)
        tables->del((deleteTable));
    HeapTable& colTable = (HeapTable&) SQLExec::tables->get_table(Columns::TABLE_NAME);
    Handles delColHandles = *colTable.select(&tableName);
    for(auto const& deleteColTable : delColHandles)
        colTable.del((deleteColTable));
    std::string message = "Table " + name + " dropped";
    return new QueryResult(message);
}

QueryResult *SQLExec::show(const hsql::ShowStatement *statement)  {
    switch(statement->type) {
        case (hsql::ShowStatement::EntityType::kTables):
            return show_tables((const hsql::ShowStatement *) statement);
        case (hsql::ShowStatement::EntityType::kColumns):
            return show_columns((const hsql::ShowStatement *) statement);
        case (hsql::ShowStatement::EntityType::kIndex):
            return new QueryResult("Index Not Implemented");
    }
}
QueryResult *SQLExec::show_tables(const hsql::ShowStatement *statement) {
    ColumnNames *colNames = new ColumnNames();
    ColumnAttributes *colAttributes = new ColumnAttributes();
    ValueDicts* rows = new ValueDicts();
    tables->get_columns(Tables::TABLE_NAME, *colNames, *colAttributes);
    HeapTable &tableNames = (HeapTable&)tables->get_table(Tables::TABLE_NAME);

    Handles* handles = tableNames.select();

    for(auto const& handle: *handles) {
        ValueDict* valHandle = tableNames.project(handle);
        Value val = (*valHandle)["table_name"];
        if(val.s!=Tables::TABLE_NAME&&val.s!=Columns::TABLE_NAME)
            rows->push_back(valHandle);
    }
    std::string message = "successfully returned "+ std::to_string(rows->size())+" rows";
    return new QueryResult(colNames, colAttributes, rows,message);
}

QueryResult *SQLExec::show_columns(const hsql::ShowStatement *statement) {
    ColumnNames *colNames = new ColumnNames();
    ColumnAttributes *colAttributes = new ColumnAttributes();
    ValueDicts* rows = new ValueDicts();
    HeapTable &colTable = (HeapTable&)tables->get_table(Columns::TABLE_NAME);
    tables->get_columns(Columns::TABLE_NAME, *colNames, *colAttributes);
    if(colNames->size()==0)
        return new QueryResult("Table not found");
    Handles* handles = colTable.select();
    for(auto const& handle: *handles) {
        ValueDict* valHandle = colTable.project(handle);
        Value val = (*valHandle)["table_name"];
        if(val.s==statement->tableName)
            rows->push_back(valHandle);
    }
    std::string message = "successfully returned "+ std::to_string(rows->size())+" rows";
    return new QueryResult(colNames, colAttributes, rows,message);
}
