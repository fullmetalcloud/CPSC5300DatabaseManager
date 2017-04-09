
#include <iostream>
#include "heap_storage.h"
#include "SQLParser.h"

using namespace std;
using namespace hsql;

DbEnv* _DB_ENV;

void PrintOpExpr(Expr* expr);
void PrintSelectStatement(const SelectStatement* stmt);
void PrintTable(TableRef* table);

void PrintExpr(Expr* expr)
{
    switch(expr->type)
    {
        case kExprLiteralFloat:
            printf("%f ",expr->fval);
            break;
        case kExprLiteralString:
            printf("%s ",expr->name);
            break;
        case kExprLiteralInt:
            printf("%lli ",expr->ival);
            break;
        case kExprStar:
            printf("* ");
            break;
        case kExprColumnRef:
            printf("%s ", expr->name);
            break;
        case kExprFunctionRef:
            printf("%s ",expr->name);
            printf(".%s ",expr->expr->name);
            break;
        case kExprOperator:
            PrintOpExpr(expr);
            break;
        case kExprSelect:
            break;
        case kExprPlaceholder:
            break;
    }
}
void PrintOpExpr(Expr* expr)
{
    if(expr->expr->alias != NULL)
    {
        printf("%s", expr->expr->alias);
        printf(".");
    }
    else if(expr->expr->table != NULL)
    {
        printf("%s", expr->expr->table);
        printf(".");
    }
    PrintExpr(expr->expr);
    switch(expr->opType)
    {
        case Expr::SIMPLE_OP:
            printf("%c ", expr->opChar);
            break;
        case Expr::AND:
            printf("AND ");
            break;
        case Expr::OR:
            printf("OR ");
            break;
        case Expr::NOT:
            printf("NOT ");
            break;
        default:
            printf("%u ",expr->opType);
            break;
    }
    if(expr->expr2->alias != NULL)
    {
        printf("%s", expr->expr2->alias);
        printf(".");
    }
    else if(expr->expr2->table != NULL)
    {
        printf("%s", expr->expr2->table);
        printf(".");
    }
    PrintExpr(expr->expr2);
}
void PrintJoin(JoinDefinition* join)
{
    switch(join->type)
    {
        case kJoinInner:
            printf("INNER JOIN ");
            break;
        case kJoinOuter:
            printf("OUTER JOIN ");
            break;
        case kJoinLeft:
            printf("LEFT JOIN ");
            break;
        case kJoinRight:
            printf("RIGHT JOIN ");
            break;
        case kJoinLeftOuter:
            printf("LEFT OUTER JOIN ");
            break;
        case kJoinRightOuter:
            printf("RIGHT OUTER JOIN ");
            break;
        case kJoinCross:
            printf("CROSS JOIN ");
            break;
        case kJoinNatural:
            printf("NATURAL JOIN ");
            break;
    }
}

void PrintTable(TableRef* table)
{
    switch(table->type)
    {
        case kTableName:
            printf("%s ",table->name);
            break;
        case kTableSelect:
            PrintSelectStatement(table->select);
            break;
        case kTableJoin:
            PrintTable(table->join->left);
            PrintJoin(table->join);
            PrintTable(table->join->right);
            printf("ON ");
            PrintExpr(table->join->condition);
            break;
        case kTableCrossProduct:
            vector<TableRef*> tbl = *table->list;
            for(int i =0; i < tbl.size()-1;i++)
            {
                PrintTable(tbl[i]);
                printf(", ");
            }
            PrintTable(tbl[tbl.size()-1]);
            break;
    }
    if (table->alias != NULL) {
        printf("AS %s ",table->alias);
    }
}
void PrintSelectStatement(const SelectStatement* stmt)
{
    printf("SELECT ");
    std::vector<Expr*> selectList = *stmt->selectList;

    for(int i =0; i < selectList.size()-1;i++)
    {
        if(selectList[i]->table != NULL)
            printf("%s.", selectList[i]->table);
        PrintExpr(selectList[i]);
        printf(", ");
    }
    if(selectList[selectList.size()-1]->table != NULL)
        printf("%s.", selectList[selectList.size()-1]->table);
    PrintExpr(selectList[selectList.size()-1]);
    printf("FROM ");
    PrintTable(stmt->fromTable);
    if (stmt->whereClause != NULL) {
        printf("WHERE ");
        PrintExpr(stmt->whereClause);
    }
    if (stmt->unionSelect != NULL) {
        PrintSelectStatement(stmt->unionSelect);
    }
    if (stmt->order != NULL) {
        printf("ORDER BY ");
        PrintExpr(stmt->order->at(0)->expr);
        if (stmt->order->at(0)->type == kOrderAsc)
            printf("ASC");
        else
            printf("DESC ");
    }
    if (stmt->limit != NULL) {
        printf("LIMIT ");
        printf("%lld ",stmt->limit->limit);
    }
    printf("\n");
}
void PrintCreateType(ColumnDefinition* col)
{
    switch(col->type)
    {
        case ColumnDefinition::UNKNOWN:
            printf("UNKNOWN");
            break;
        case ColumnDefinition::TEXT:
            printf("TEXT");
            break;
        case ColumnDefinition::INT:
            printf("INT");
            break;
        case ColumnDefinition::DOUBLE:
            printf("DOUBLE");
            break;
    }
}
void PrintTableType(const CreateStatement* stmt)
{
    switch(stmt->type)
    {
        case CreateStatement::kTable:
            printf("TABLE ");
            break;
        case CreateStatement::kTableFromTbl: // Hyrise file format
            printf("SPECIALTABLE");
            break;
        case CreateStatement::kView:
            printf("VIEW ");
            break;
    }
}
void PrintCreateStatement(const CreateStatement* stmt)
{
    printf("CREATE ");
    PrintTableType(stmt);
    printf("%s (", stmt->tableName);
    std::vector<ColumnDefinition*> cols = *stmt->columns;

    for(int i =0; i < cols.size()-1;i++)
    {
        printf("%s ",cols[i]->name);
        PrintCreateType(cols[i]);
        printf(", ");
    }
    printf("%s ",cols[cols.size()-1]->name);
    PrintCreateType(cols[cols.size()-1]);
    printf(")\n");
}
void PrintStatement(const SQLStatement* stmt)
{
    switch (stmt->type())
    {
        case kStmtSelect:
            PrintSelectStatement((const SelectStatement*) stmt);
            break;
        case kStmtCreate:
            PrintCreateStatement((const CreateStatement*) stmt);
            break;
        case kStmtImport:
            break;
        case kStmtInsert:
            break;
        case kStmtUpdate:
            break;
        case kStmtDelete:
            break;
        case kStmtDrop:
            break;
        case kStmtPrepare:
            break;
        case kStmtExecute:
            break;
        case kStmtExport:
            break;
        case kStmtRename:
            break;
        case kStmtAlter:
            break;
        case kStmtError:
            break;
    }
}
int
main(int argc, char* argv[])
{
    if(argc != 2){
        cerr<<"SQL USE: (dbenv path)"<<endl;
        return 1;
    }
    const char* envHome = argv[1];
    const char *home = std::getenv("HOME");
    string envDir = string(home)+"/"+string(envHome);
    _DB_ENV = new DbEnv(0U);
    _DB_ENV->set_message_stream(&std::cout);
    _DB_ENV->set_error_stream(&std::cerr);
    try{
        _DB_ENV->open(envDir.c_str(), DB_CREATE | DB_INIT_MPOOL, 0);
    }catch(DbException& e){
        cerr<<"(SQL Error: "<<e.what()<<")";
        return 1;
    }
    string query = "";
    cout<<"(running with database environment at "<<envDir<<")"<<endl;
    cout<<"TESTING SLOTTED PAGE"<<endl;
    if(test_slotted_page())
        cout<<"SLOTTED PAGE SUCCESS!"<<endl;
    else
        cout<<"SLOTTED PAGE FAIL"<<endl;


    cout<<"TESTING HEAP STORAGE"<<endl;
    if(test_heap_storage())
        cout<<"HEAP STORAGE SUCCESS!"<<endl;
    else
        cout<<"HEAP STORAGE FAIL"<<endl;

    cout<< endl <<"SQL PARSER TEST"<<endl;
    cout<<"TYPE \"quit\" TO LEAVE!"<<endl;
    while(query != "quit")
    {
        cout<<"  SQL >> ";
        getline(cin,query);
        SQLParserResult* result = SQLParser::parseSQLString(query);
        if(result->isValid())
        {
            for(int i = 0; i<result->size();i++)
                PrintStatement(result->getStatement(i));
        }
        else if(query == "quit"){ }
        else
            cout << "NOT VALID QUERY:  "<< query << endl;
        delete result;
    }
    cout<<endl<<"GOODBYE"<<endl;
    return 0;
}
