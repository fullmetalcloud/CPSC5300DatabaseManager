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
        put_header();
        put_header(num_records,size,end_free+1);
        memcpy(address(end_free+1), data->get_data(), size);
    }
    return num_records;

}
Dbt* SlottedPage::get(RecordID record_id){
    //gets data of given record id
    u_int16_t size, location;
    get_header(size, location, record_id);
    if(location == 0)
        return nullptr;
    return new Dbt(address(location),size);

}
void SlottedPage::put(RecordID record_id, const Dbt &data) throw(DbBlockNoRoomError){
    //puts given data into the given record id, must check if new
    // data can fit and slide block data to adjust to new data
    u_int16_t size, location, newSize;
    newSize = (u_int16_t)data.get_size();
    get_header(size, location, record_id);
    if(!has_room(newSize))
        throw DbBlockNoRoomError("Not enough room!");
    //check if new data is larger than old data
    if(newSize > size) {
        slide(location,location-newSize-size);
        memcpy(address(location-newSize-size), data.get_data(),newSize);
    }
    else {
        memcpy(address(location),data.get_data(),newSize);
        slide(location+newSize,location+size);
    }
    //update header of record id of new data and size
    get_header(size,location,record_id);
    put_header(record_id,newSize,location);
}

void SlottedPage::del(RecordID record_id){
    //delete data of given record id out of block
    u_int16_t size, location;
    get_header(size,location,record_id);
    put_header(record_id, 0, 0);
    slide(location, location+size);
}
RecordIDs* SlottedPage::ids(void){
    //get all record ids in block
    RecordIDs* records = new RecordIDs;
    u_int16_t size, location;
    for(u_int16_t i = 1; i<=num_records;i++)
    {
        get_header(size, location, i);
        if(location!=0)
            records->push_back(i);
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
}
bool SlottedPage::has_room(u_int16_t size){
    //checks if there is space for new data
    return (end_free - (num_records + 1) * 4 >= size);
}
void SlottedPage::slide(u_int16_t start, u_int16_t end){
    //slides data if changing data in record or deleting data in block
    u_int16_t shiftSize = end - start;
    u_int16_t size, location;
    if(shiftSize==0)
        return;
    //shift all data before given start
    void* to = address(end_free + shiftSize + 1);
    void* from = address(end_free + 1);
    char shiftData[start - (end_free+1)];
    memcpy(shiftData, from, start - (end_free+1));
    memcpy(to, shiftData, start - (end_free+1));
    RecordIDs* records = ids();
    //adjust headers
    for(RecordIDs::iterator i = records->begin();i!=records->end();i++) {
        get_header(size,location, *i);
        if(location<=start)
            put_header(*i,size,location+shiftSize);
    }
    end_free+=shiftSize;
    put_header();
}
u_int16_t SlottedPage::get_n(u_int16_t offset) const {
    //gets data at the given offset
    return *(u_int16_t*) address(offset);
}
void SlottedPage::put_n(u_int16_t offset, u_int16_t n){
    //puts data into given offset
    *(u_int16_t *)address(offset) = n;
}
void* SlottedPage::address(u_int16_t offset)const {
    //retrieves data from block
    return (void*)((char*)block.get_data() + offset);
}
bool test_slotted_page(){
    char data[DB_BLOCK_SZ];
    Dbt* check;
    memset(data, 0, sizeof(data));
    Dbt block(data, sizeof(data));
    SlottedPage testPage(block, 1, true);
    char word1[] = "Hello";
    Dbt test1(word1, sizeof("Hello"));
    RecordID id1 = testPage.add(&test1);
    char word2[] = "Wow!";
    Dbt test2(word2, sizeof("Wow!"));
    RecordID id2 = testPage.add(&test2);
    RecordIDs* ids = testPage.ids();
    cout<<"   TESTING ADD"<<endl;
    for(vector<RecordID>::iterator testID = ids->begin();
        testID != ids->end();
        testID++){
        check = testPage.get(*testID);
        string testWord = (char*)check->get_data();
        cout<<testWord<<" ";
        if(testWord.compare(word1)!=0 && testWord.compare(word2)!=0){
            cout<<"   ADD FAILED"<<endl;
            return false;
        }
    }
    cout<<endl<<"   ADD SUCCESSFUL"<<endl;
    cout<<"   TESTING PUT 1"<<endl;
    char word3 []="Goodbye";
    Dbt test3(word3, sizeof(word3));
    testPage.put(id1, test3);
    ids = testPage.ids();
    for(RecordIDs::iterator testID = ids->begin();
        testID != ids->end();
        testID++){
        check = testPage.get(*testID);
        string testWord = (char*)check->get_data();
        cout<<testWord<<" ";
        if(testWord.compare(word3)!=0 && testWord.compare(word2)!=0){
            cout<<"   PUT 1 FAILED"<<endl;
            return false;
        }
    }
    cout<<endl<<"   PUT 1 SUCCESSFUL"<<endl;
    cout<<"   TESTING PUT 2"<<endl;
    char word4 []="Hi";
    Dbt test4(word4, sizeof(word4));
    testPage.put(id2, test4);
    for(RecordIDs::iterator testID = ids->begin();
        testID != ids->end();
        testID++){
        check = testPage.get(*testID);
        string testWord = (char*)check->get_data();
        cout<<testWord<<" ";
        if(testWord.compare(word3)!=0 && testWord.compare(word4)!=0){
            cout<<"   PUT 2 FAILED"<<endl;
            return false;
        }
    }
    cout<<endl<<"   PUT 2 SUCCESSFUL"<<endl;
    cout<<"   TESTING DELETE"<<endl;
    testPage.del(id1);
    ids = testPage.ids();
    for(RecordIDs::iterator testID = ids->begin();
        testID != ids->end();
        testID++){
        check = testPage.get(*testID);
        string testWord = (char*)check->get_data();
        cout<<testWord<<" ";
        if(testWord.compare(word4)!=0){
            cout<<endl<<"   DELETE FAILED"<<endl;
            return false;
        }
    }
    cout<<endl<<"   DELETE SUCCESSFUL"<<endl;
    cout<<"   TESTING ADD 2"<<endl;
    RecordID id3 = testPage.add(&test1);
    ids = testPage.ids();
    for(vector<RecordID>::iterator testID = ids->begin();
        testID != ids->end();
        testID++){
        check = testPage.get(*testID);
        string testWord = (char*)check->get_data();
        cout<<testWord<<" ";
        if(testWord.compare(word1)!=0 && testWord.compare(word4)!=0){
            cout<<endl<<"   ADD 2 FAILED"<<endl;
            return false;
        }
    }
    cout<<endl<<"   ADD 2 SUCCESSFUL"<<endl;
    return true;
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
    db.remove(dbfilename.c_str(),nullptr,0);
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
    int id = ++last;
    Dbt key(&id,sizeof(id));
    char newBlock[DB_BLOCK_SZ];
    memset(newBlock,0,sizeof(newBlock));
    Dbt data(newBlock,sizeof(newBlock));
    db.put(nullptr, &key, &data, 0);
    db.get(nullptr, &key, &data, 0);
    SlottedPage* result = new SlottedPage(data,id,true);
    db.put(nullptr, &key, &data, 0);
    return result;
}
SlottedPage* HeapFile::get(BlockID block_id){
    //get block of given block id
    Dbt data;
    Dbt key(&block_id,sizeof(block_id));
    db.get(nullptr, &key, &data, 0);
    return new SlottedPage(data, block_id,false);
}
void HeapFile::put(DbBlock* block){
    //put data into block of given block id
    //(id and data in parameter block)
    BlockID blockKey = block->get_block_id();
    Dbt key(&blockKey,sizeof(blockKey));
    db.put(nullptr, &key, block->get_block(), 0);
}
BlockIDs* HeapFile::block_ids(){
    //return all block ids
    BlockIDs* ids = new BlockIDs();
    for (u_int32_t i = 1; i<=last;i++) {
        ids->push_back(i);
    }
    return ids;
}
void HeapFile::db_open(uint flags){
    //open or create berkeley db file
    DB_BTREE_STAT stat;
    if(!closed)
        return;
    db.set_re_len(DB_BLOCK_SZ);
    dbfilename = name + ".db";
    db.open(nullptr, dbfilename.c_str(), nullptr, DB_RECNO, flags, 0644);
    if(flags == 0){
        db.stat(nullptr, &stat, 0);
        last = stat.bt_ndata;
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
    for(BlockIDs::iterator blockID = blockIDs->begin();
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
    for (ColumnNames::const_iterator i = column_names.begin();
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
    for(ColumnNames::iterator i = column_names.begin();
        i != column_names.end();
        i++, count++) {
        rowInfo = row->find(*i);
        value = rowInfo->second;

        columnType = column_attributes[count].get_data_type();
        if(columnType == ColumnAttribute::INT) {
            *(u_int16_t*)(tempBlock + dataSize) = (u_int16_t) value.n;
            dataSize += sizeof(u_int16_t);
        } else if(columnType == ColumnAttribute::TEXT) {
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
    delete [] tempBlock;
    delete [] data;
    return result;
}
ValueDict* HeapTable::unmarshal(Dbt* data){
    //convert block data into row data
    unsigned int textSize = 0, count = 0, offset = 0, size = data->get_size();
    char block[size];
    memcpy(block,data->get_data(),size);
    ValueDict* result = new ValueDict();
    Value value;
    for(ColumnNames::iterator i = column_names.begin();
        i != column_names.end();
        i++, count++) {
        if(column_attributes[count].get_data_type() == ColumnAttribute::INT){
            value.data_type = ColumnAttribute::INT;
            value.n = *(u_int16_t*) (block + offset);
            offset+= sizeof(u_int16_t);
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
    value1[0].n = 1;
    value1[1].s = "Apples";
    value1[2].s = "Oranges";
    Value value2[3];
    value2[0].n = 5;
    value2[1].s = "Kappa";
    value2[2].s = "Klappa";
    for(int i  = 0; i<3; ++i) {
        colNames.push_back(testColNames[i].c_str());
        colAttributes.push_back(testColAttributes[i]);
        (*insertTest1)[testColNames[i].c_str()] = value1[i];
        (*insertTest2)[testColNames[i].c_str()] = value2[i];
    }
    cout<<"   ATTEMPTING TABLE CREATION"<<endl;
    HeapTable table(tableName,colNames, colAttributes);
    table.create_if_not_exists();
    cout<<"   TABLE CREATION SUCCESSFUL!"<<endl;
    cout<<"   ATTEMPTING DROP"<<endl;
    table.drop();
    cout<<"   DROP SUCCESSFUL"<<endl;
    table.create_if_not_exists();
    cout<<"   ATTEMPTING INSERT 1"<<endl;
    table.insert(insertTest1);
    cout<<"   INSERT 1 SUCCESSFUL!"<<endl;
    cout<<"   ATTEMPTING SELECT 1"<<endl;
    handles = table.select();
    cout<<"   SELECT 1 SUCCESSFUL!"<<endl;
    cout<<"   NUMBER OF HANDLES: "<<handles->size()<<endl;
    cout<<"   ATTEMPTING INSERT 2 AND SELECT 2"<<endl;
    table.insert(insertTest2);
    handles = table.select();
    cout<<"   INSERT 2 AND SELECT 2 SUCCESSFUL! "<<endl;
    cout<<"   NUMBER OF HANDLES: "<<handles->size()<<endl;
    cout<<"   ATTEMPTING PROJECT"<<endl;
    for(Handles::iterator handle = handles->begin();
        handle!=handles->end();
        handle++){
        ValueDict* project = table.project(*handle);
        for(int j = 0; j<3;j++) {
            Value value = (*project)[colNames[j]];
            if(value.data_type==ColumnAttribute::INT)
                cout<<value.n<<" ";
            else if(value.data_type==ColumnAttribute::TEXT)
                cout<<value.s<<" ";
        }
        cout<<endl;
    }
    cout<<"   PROJECT SUCCESSFUL!"<<endl;

    delete insertTest1;
    delete insertTest2;
    return true;
}

