//
// Created by Edward Guevara on 4/5/17.
//

#include "heap_storage.h"
#include <iostream>

using namespace std;

//SlottedPage Implementation
SlottedPage::SlottedPage(Dbt &block, BlockID block_id, bool is_new)
        : DbBlock(block, block_id, is_new) {
    if(is_new) {
        num_records = 0;
        end_free = DB_BLOCK_SZ-1;
        put_header();
    } else
        get_header(num_records, end_free);
}
RecordID SlottedPage::add(const Dbt* data) throw(DbBlockNoRoomError){
    //check if there is space for data and record header
    if(!has_room((u_int16_t)data->get_size()))
        throw DbBlockNoRoomError("Not enough room!");
    else {
        ++num_records;
        u_int16_t size = (u_int16_t) data->get_size();
        end_free -= size;
        put_header(num_records,size,end_free);
        put_header();
        memcpy(address(end_free), data->get_data(), size);
    }
    return num_records;

}
Dbt* SlottedPage::get(RecordID record_id){
    //gets data of given record id
    u_int16_t size, loc;
    get_header(size, loc, record_id);
    if(loc == 0)
        return nullptr;
    return new Dbt(address(loc),size);

}
void SlottedPage::put(RecordID record_id, const Dbt &data) throw(DbBlockNoRoomError){
    //puts given data into the given record id, must check if new
    // data can fit and slide block data to adjust to new data
    cout<<data.get_size()<<" "<<data.get_data()<<endl;
    u_int16_t size, location, newSize;
    newSize = (u_int16_t)data.get_size();
    get_header(size, location, record_id);
    //check if new data is larger than old data
    if(newSize > size) {
        if(!has_room(newSize-size))
            throw DbBlockNoRoomError("Not enough room!");
        put_header();
        put_header(record_id,newSize,location);
        slide(location,location-newSize-size);
        memcpy(address(location), data.get_data(),newSize);
    }
    else {
        memcpy(address(location),data.get_data(),newSize);
        slide(location+newSize,location+size);
    }
    //update header of record id of new data and size
    get_header(size,location,record_id);
    put_header(record_id,newSize,location+newSize-size);
}

void SlottedPage::del(RecordID record_id){
    //delete data of given record id out of block
    u_int16_t size, location;
    get_header(size,location,record_id);
}
RecordIDs* SlottedPage::ids(void){
    //get all record ids in block
    RecordIDs* records = new RecordIDs;
    for(unsigned int i = 1; i<num_records;i++)
    {
        records->push_back(get_n(i * 4));
    }
    return records;
}
void SlottedPage::get_header(u_int16_t &size, u_int16_t &loc, RecordID id){
    //get header of given record id
    size = get_n(id * 4);
    loc = get_n(id * 4 + 2);
}
void SlottedPage::put_header(RecordID id, u_int16_t size, u_int16_t loc){
    //puts header of given id into block
    if(id == 0) {
        size = num_records;
        loc = end_free;
    }
    put_n(id*4, size);
    put_n(id*4 + 2, loc);
    cout<<id<<": "<<size<<" "<<loc<<endl;
}
bool SlottedPage::has_room(u_int16_t size){
    //checks if there is space for new data
    return end_free - (num_records + 1) * 4 >= size;
}
void SlottedPage::slide(u_int16_t start, u_int16_t end){
    //slides data if changing data in record or deleting data in block
    u_int16_t shiftSize = end - start;
    if(shiftSize==0)
        return;
    void* to = address(end_free + shiftSize + 1);
    void* from = address(end_free + 1);
    char shiftData[start - end_free + 1];
    memcpy(shiftData,from,shiftSize);
    memcpy(to,shiftData,shiftSize);
    RecordIDs* records = ids();
    //shift all data before given start
    for(unsigned int i = 0; records->size();i++) {
        u_int16_t size, location;
        get_header(size,location, (*records)[i]);
        if(location<=start)
            put_header((*records)[i],size,location+shiftSize);
    }
    end_free+=shiftSize;
    put_header();
}
u_int16_t SlottedPage::get_n(u_int16_t offset){
    //gets data at the given offset
    return *(u_int16_t*) address(offset);
}
void SlottedPage::put_n(u_int16_t offset, u_int16_t n){
    //puts data into given offset
    *(u_int16_t *)address(offset) = n;
}
void* SlottedPage::address(u_int16_t offset){
    //retrieves data from block
    return (void*)((char*)block.get_data()+ offset);
}

//HeapFile Implementation
void HeapFile::create() {
    //create the db file
    db_open(DB_CREATE | DB_EXCL);
    get_new();
}
void HeapFile::drop(){
    //drop/delete file
    Db db(_DB_ENV,0);
    db.remove(dbfilename.c_str(),NULL,0);
}
void HeapFile::open(){
    //open file
    db_open();
}
void HeapFile::close(){
    //close file (not delete)
    db.close(0);
    closed = true;
}
SlottedPage* HeapFile::get_new(){
    //make new block
    BlockID id = ++last;
    Dbt key(&id,sizeof(id));
    char newBlock[DB_BLOCK_SZ];
    memset(newBlock,0,sizeof(newBlock));
    Dbt data(newBlock,sizeof(newBlock));
    db.put(NULL, &key, &data, 0);
    db.get(NULL, &key, &data, 0);
    SlottedPage* result = new SlottedPage(data,id,true);
    db.put(NULL, &key, &data, 0);
    return result;
}
SlottedPage* HeapFile::get(BlockID block_id){
    //get block of given block id
    Dbt data;
    Dbt key(&block_id,sizeof(block_id));
    db.get(NULL, &key, &data, 0);
    return new SlottedPage(data, block_id,false);
}
void HeapFile::put(DbBlock* block){
    //put data into block of given block id
    //(id and data in parameter block)
    BlockID blockKey = block->get_block_id();
    Dbt key(&blockKey,sizeof(blockKey));
    db.put(NULL, &key, block->get_block(), 0);
}
BlockIDs* HeapFile::block_ids(){
    //return all block ids
    BlockIDs* ids = new BlockIDs();
    for (u_int32_t i = 1; i<last;i++) {
        ids->push_back(i);
    }
    return ids;
}
void HeapFile::db_open(uint flags){
    //open or create berkeley db file
    if(!closed)
        return;
    db.set_re_len(DB_BLOCK_SZ);
    dbfilename = name + ".db";
    db.open(nullptr, dbfilename.c_str(),nullptr,DB_RECNO, flags, 0644);
    if(flags == 0){
        DB_BTREE_STAT stat;
        db.stat(NULL, &stat, DB_FAST_STAT);
        last = stat.bt_ndata;
    } else {
        last = 0;
    }
    closed = false;
}

//HeapTable Implementation
HeapTable::HeapTable(Identifier table_name, ColumnNames column_names, ColumnAttributes column_attributes )
        : DbRelation(table_name,column_names,column_attributes), file(table_name) { }

void HeapTable::create(){
    //create table
    file.create();
}
void HeapTable::create_if_not_exists(){
    //check if table exists, and create if it does not
    try{
        file.open();
    }catch(DbException& e) {
        file.create();
    }
}
void HeapTable::drop(){
    //drop/delete table
    file.drop();
}
void HeapTable::open(){
    //open table
    file.open();
}
void HeapTable::close(){
    //close table (not delete)
    file.close();
}
Handle HeapTable::insert(const ValueDict* row){
    //insert row of data into table (append() for adding)
    open();
    ValueDict* dataAdded = validate(row);
    Handle result = append(dataAdded);
    delete dataAdded;
    return result;
}
void HeapTable::update(const Handle handle, const ValueDict* new_values){
    //update row in table
    throw DbRelationError("NOT IMPLEMENTED");
}
void HeapTable::del(const Handle handle){
    //delete row in table
    throw DbRelationError("NOT IMPLEMENTED");
}

Handles* HeapTable::select(){
    //return all rows in table
    ValueDict temp;
    return select(&temp);
}
Handles* HeapTable::select(const ValueDict* where){
    //return rows that match conditions of where statement
    Handles* result = new Handles();
    Handle handle;
    SlottedPage* block;
    RecordIDs* records;
    BlockIDs* blockIDs = file.block_ids();
    cout<<blockIDs->size()<<endl;
    for(vector<BlockID>::iterator blockID = blockIDs->begin();
        blockID != blockIDs->end();
        blockID++) {
        block = file.get(*blockID);
        records = block->ids();
        for(vector<RecordID>::iterator recordID = records->begin();
            recordID != records->end();
            recordID++) {
            handle.first = *blockID;
            handle.second = *recordID;
            result->push_back(handle);
        }
    }
    return result;
}
ValueDict* HeapTable::project(Handle handle){
    //project all columns in table
    return project(handle, &column_names);
}
ValueDict* HeapTable::project(Handle handle, const ColumnNames* column_names){
    //show all rows with given columns in table
    SlottedPage* block = file.get(handle.first);
    Dbt* blockData = block->get(handle.second);
    ValueDict* data = unmarshal(blockData);
    ValueDict* result = new ValueDict();
    if(column_names->empty())
        return data;
    for(vector<Identifier>::const_iterator i = column_names->begin();
        i<column_names->end();
        i++) {
        (*result) [*i] = (*data) [*i];
    }
    return result;
}

ValueDict* HeapTable::validate(const ValueDict* row) {
    //validate row if it can be added to table
    ValueDict* result = new ValueDict();
    Value value;
    ValueDict::const_iterator rowInfo;
    for (vector<Identifier>::const_iterator i = column_names.begin();
         i != column_names.end();
         i++) {
        rowInfo = row->find(*i);
        if(rowInfo==row->end()){
            throw DbRelationError("NULL row value NOT IMPLEMENTED");
        } else {
            value = rowInfo->second;
        }
        (*result) [*i] = value;
    }

    return result;
}
Handle HeapTable::append(const ValueDict* row){
    //add row data to file and check if new blocks are necessary
    Dbt* newData = marshal(row);
    SlottedPage* block = file.get(file.get_last_block_id());

    RecordID recordID;
    Handle result;
    try {
        recordID = block->add(newData);
    } catch(DbException& e) {
        block = file.get_new();
        recordID = block->add(newData);
    }
    file.put(block);
    result.first = file.get_last_block_id();
    result.second = recordID;
    return result;
}
Dbt* HeapTable::marshal(const ValueDict* row) {
    //convert row data into block data
    unsigned int count = 0;
    unsigned int dataSize = 0;
    unsigned int size = 0;
    char *tempBlock = new char[DB_BLOCK_SZ];
    Value value;
    ValueDict::const_iterator rowInfo;
    ColumnAttribute::DataType columnType;
    for(vector<Identifier>::iterator i = column_names.begin();
        i != column_names.end();
        i++, count++) {
        rowInfo = row->find(*i);
        value = rowInfo->second;

        columnType = column_attributes[count].get_data_type();
        if(columnType == ColumnAttribute::INT) {
            *(int32_t*)(tempBlock + dataSize) = value.n;
            dataSize += sizeof(int32_t);
        }
        else if(columnType == ColumnAttribute::TEXT) {
            size = (unsigned int) value.s.length();
            *(u_int16_t*)(tempBlock + dataSize) = (u_int16_t)size;
            dataSize+=sizeof(u_int16_t);
            memcpy(tempBlock+dataSize, value.s.c_str(), size);
            dataSize+=size;
        } else {
          throw DbRelationError("Only marshals INT and TEXT");
        }
    }
    char* data = new char[dataSize];
    memcpy(data, tempBlock, dataSize);
    Dbt* result = new Dbt(data,dataSize);
    delete tempBlock;
    delete data;
    return result;
}
ValueDict* HeapTable::unmarshal(Dbt* data){
    //convert block data into row data
    unsigned int textSize = 0, count = 0, offset = 0, size = data->get_size();
    char block[size];
    memcpy(block,data->get_data(),size);
    ValueDict* result = new ValueDict();
    Value value;
    for(vector<Identifier>::iterator i = column_names.begin();
        i != column_names.end();
        i++, count++) {
        if(column_attributes[count].get_data_type() == ColumnAttribute::INT){
            value.data_type = ColumnAttribute::INT;
            value.n = *(int32_t*) (block + offset);
            offset+= sizeof(int32_t);
        }
        else if(column_attributes[count].get_data_type() == ColumnAttribute::TEXT){
            textSize = *(u_int16_t*)(block + offset);
            offset+=sizeof(u_int16_t);
            value.data_type = ColumnAttribute::TEXT;
            char temp [textSize];
            memcpy(temp, (block + offset), textSize);
            temp[textSize] = '\0';
            value.s = temp;
            offset+=textSize;
        } else {
            throw DbRelationError("Only unmarshals INT and TEXT");
        }
        (*result)[*i] = value;
    }
    return result;
}
bool test_heap_storage(){
    Dbt testData;
    SlottedPage* testPage;
    string tableName = "TestTable";
    string testColNames [3]{"Number","Text1", "Text2"};
    ColumnAttribute testColAttributes [3] {ColumnAttribute::INT, ColumnAttribute::TEXT,
                                           ColumnAttribute::TEXT};
    ColumnNames colNames;
    ColumnAttributes colAttributes;
    ValueDict* insertTest1 = new ValueDict();
    ValueDict* insertTest2 = new ValueDict();
    Handles* handles;
    Value value1[3];
    value1[0].n = 102;
    value1[1].s = "Apples";
    value1[2].s = "Oranges";
    Value value2[3];
    value2[0].n = 102;
    value2[1].s = "Kappa";
    value2[2].s = "Clappa";
    for(int i  = 0; i<3; ++i) {
        colNames.push_back(testColNames[i].c_str());
        colAttributes.push_back(testColAttributes[i]);
        (*insertTest1)[testColNames[i].c_str()] = value1[i];
        (*insertTest2)[testColNames[i].c_str()] = value2[i];
    }
    cout<<"ATTEMPTING TABLE CREATION"<<endl;
    HeapTable table(tableName,colNames, colAttributes);
    table.create_if_not_exists();
    cout<<"TABLE CREATION SUCCESSFUL!"<<endl;
    cout<<"ATTEMPTING INSERT 1"<<endl;
    table.insert(insertTest1);
    cout<<"INSERT 1 SUCCESSFUL!"<<endl;
    handles = table.select();
    cout<<"SELECT 1 SUCCESSFUL! "<< handles->size()<<endl;
    cout<<"ATTEMPTING INSERT AND SELECT 2"<<endl;
    table.insert(insertTest2);
    handles = table.select();
    cout<<"SELECT 2 SUCCESSFUL! "<<handles->size()<<endl;
    //ValueDict* project = table.project();

    delete insertTest1;
    delete insertTest2;
    return true;
}

