//
// Created by Edward Guevara on 5/2/17.
//
#include "btree.h"
BTreeIndex::BTreeIndex(DbRelation& relation, Identifier name, ColumnNames key_columns, bool unique)
            : DbIndex(relation, name, key_columns, unique), file(relation.get_table_name()+'_'+name) {
    build_key_profile();
    closed = true;
    stat = nullptr;
    root = nullptr;
}

BTreeIndex::~BTreeIndex() {
    delete stat;
    delete root;
}

void BTreeIndex::create(){
    //create heap file, BTreeStat, BTree root as Leaf, and
    //insert rows in table into index
    file.create();
    stat = new BTreeStat(file, STAT,STAT + 1, key_profile);
    root = new BTreeLeaf(file, stat->get_root_id(), key_profile, true);
    closed = false;
    Handles handles = *relation.select();
    try{
        for(auto const& handle : handles)
            insert(handle);
    }catch(DbRelationError& e){
        file.drop();
        throw e;
    }
}
void BTreeIndex::drop(){
    file.drop();
}

void BTreeIndex::open() {
    if(closed) {
        file.open();
        stat = new BTreeStat(file, STAT, key_profile);
        if (stat->get_height() == 1) {
            root = new BTreeLeaf(file, stat->get_root_id(), key_profile, false);
        }
        else {
            std::cout<<stat->get_root_id()<<std::endl;
            root = new BTreeInterior(file, stat->get_root_id(), key_profile, false);
        }
        closed = false;
    }
}

void BTreeIndex::close() {
    file.close();
    stat = nullptr;
    root = nullptr;
    closed = true;
}

Handles* BTreeIndex::lookup(ValueDict* key) const{
    //call recursive lookup with root, height, and tkey order
    return _lookup(root, stat->get_height(), tkey(key));
}

Handles* BTreeIndex::_lookup(BTreeNode *node, uint height, const KeyValue* key) const{
    if(height == 1) {
        //leaf level
        BTreeLeaf* leaf = (BTreeLeaf*)node;
        Handles* handles = new Handles;
        try {
            Handle handle = leaf->find_eq(key);
            handles->push_back(handle);
        }
        catch(std::out_of_range& e){
            ;
        }
        return handles;
    }
    else{
        //root/interior level
        BTreeInterior* bTreeInterior = (BTreeInterior*) node;
        return _lookup(bTreeInterior->find(key,height), height-1, key);
    }
}

Handles* BTreeIndex::range(ValueDict* min_key, ValueDict* max_key) const{
    throw DbRelationError("Range Not implemented");
}

void BTreeIndex::insert(Handle handle){
    //insert into index
    KeyValue* _tkey = tkey(relation.project(handle,&key_columns));
    Insertion newNode = _insert(root,stat->get_height(), _tkey, handle);
    if(!root->insertion_is_none(newNode)) {
        //root needs to split and new root needs to be made
        BTreeInterior* newRoot = new BTreeInterior(file,0, key_profile,true);
        newRoot->set_first(root->get_id());
        newRoot->insert(&newNode.second, newNode.first);
        stat->set_root_id(newRoot->get_id());
        stat->set_height(stat->get_height()+1);
        stat->save();
        root = newRoot;
    }
    delete _tkey;
}

Insertion BTreeIndex::_insert(BTreeNode *node, uint height, const KeyValue* key, Handle handle){
    if(height == 1) {
        //insert into leaf block
        BTreeLeaf *leaf = (BTreeLeaf *) node;
        return leaf->insert(key, handle);
    }
    else {
        //go to leaf block and insert if leaf splits
        BTreeInterior* bTreeInterior = (BTreeInterior*)node;
        Insertion newNode = _insert(bTreeInterior->find(key,height), height-1, key, handle);
        if(!node->insertion_is_none(newNode))
            return bTreeInterior->insert(&newNode.second,newNode.first);
        return BTreeNode::insertion_none();
    }
}

void BTreeIndex::del(Handle handle){
    throw DbRelationError("Delete Not implemented");
}

KeyValue *BTreeIndex::tkey(const ValueDict *key) const {
    //return values of key in order of key_columns/order of attributes
    KeyValue* result = new KeyValue;
    for(auto const& col : key_columns){
        result->push_back(key->at(col));
    }
    return result;
} // pull out the key values from the ValueDict in order

void BTreeIndex::build_key_profile(){
    //order of column attributes based on key_columns
    ColumnAttributes colAttrs = *relation.get_column_attributes(key_columns);
    for(auto col : colAttrs)
        key_profile.push_back(col.get_data_type());
}

void btree_test_set_row(ValueDict &row, int a, std::string b) {
    row["a"] = Value(a);
    row["b"] = Value(b);
}

bool test_btree() {
    ColumnNames column_names;
    column_names.push_back("a");
    column_names.push_back("b");
    ColumnAttributes column_attributes;
    ColumnAttribute ca(ColumnAttribute::INT);
    column_attributes.push_back(ca);
    ca.set_data_type(ColumnAttribute::TEXT);
    column_attributes.push_back(ca);
    HeapTable table("_test_BTree_table", column_names, column_attributes);
    table.create();
    ValueDict row;
    std::string b = "alkjsl;kj; as;lkj;alskjf;laks df;alsdkjfa;lsdkfj ;alsdfkjads;lfkj a;sldfkj a;sdlfjk a";
    Handle last_handle;
    for (int i = 0; i < 1000; i++) {
        if(i != 709){
            btree_test_set_row(row, i, b);
            last_handle = table.insert(&row);
        }
    }
    BTreeIndex testTree(table,"test",column_names,false);
    testTree.create();
    std::cout<<"create ok"<<std::endl;
    /*testTree.close();
    std::cout<<"close ok"<<std::endl;
    testTree.open();
    std::cout<<"open ok"<<std::endl;*/
    ValueDict newRow;
    btree_test_set_row(newRow,709,b);
    testTree.insert(table.insert(&newRow));
    std::cout<<"insert ok"<<std::endl;
    /*Handles handles = *table.select(&newRow);
    for(auto const& handle:handles)
        testTree.del(handle);
    std::cout<<"delete ok"<<std::endl;*/
    Handles handles = *testTree.lookup(&newRow);
    for(auto const& handle: handles) {
        ValueDict val = *table.project(handle);
        if(val["a"]!=709) {
            std::cout<<"found wrong value"<<std::endl;
            return false;
        }
    }
    std::cout<<"lookup ok"<<std::endl;
    testTree.drop();
    std::cout<<"drop ok"<<std::endl;
    table.drop();
    return true;
}