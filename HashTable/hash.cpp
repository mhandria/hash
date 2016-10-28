//
//  hash.cpp
//  HashTable
//
//  Created by Michael Handria on 9/19/16.
//  Copyright © 2016 Michael Handria. All rights reserved.
//

#include "hash.hpp"
#include "list.hpp"
#include <string>
#include <iostream>

using namespace std;


//CONSTRUCTOR
//
//return an instance of the class
//with pre-allocated space for the given
//number of objects.

Hash::Hash(int s){
    
    //initializes a pointer to an array of LinkedList;
    pntr = new List[s];
    
    
    size = s;
    items = 0;
}

//DESTRUCTOR
Hash::~Hash(){
    
    //delete all pointers and LinkedList
    delete []pntr;
}


//ADD METHOD
//
//stores the given key/value pair in
//the hash map. Returns a boolean value
//indicating success / failure of the operation.

bool Hash::set(string key, string value){
    
    // ----------    implement djb2 hash algorithm ----------//
    unsigned long hash = 5381;
    char *c;
    int itr = 0;
    while (itr < key.length()){
        c = &key[itr];
        hash = ((hash << 5) + hash) + (int)*c;
        itr++;
    }
    // -------------------------------------------------------//
    
    // OLD HASH FUNCTION
    // --> int hasFunct = (key[0]*31 - key[key.length()-1])%size; <--//
    
    //to set the boundaries within the size of the hash table
    int hasFunct = hash%size;

    //if the number of items is = to the size of the hash
    //table then do not allow the value to be stored into the
    //hash table
    if(size == items){
        return false;
    }
    
    //else add the object into the hash table
    else{
        
        //allocate a new node to be stored into the
        //hash table
        Node *n = new Node;
        
        //set their values
        n->key = key;
        n->val = value;
        
        //store it into the linked list in the
        //hash table
        (pntr+hasFunct)->append(n);
        
        //increment the items value
        items++;
        return true;
    }
}

//GET METHOD
//
//return the value associated
//with the given key, or null if no value is set.

string Hash::get(string key){
    
    // ----------    implement djb2 hash algorithm ----------//
    unsigned long hash = 5381;
    char *c;
    int itr = 0;
    while (itr < key.length()){
        c = &key[itr];
        hash = ((hash << 5) + hash) + (int)*c;
        itr++;
    }
    // -------------------------------------------------------//
    
    // OLD HASH FUNCTION
    // --> int hasFunct = (key[0]*31 - key[key.length()-1])%size; <--//
    
    //to set the boundaries within the size of the hash table
    int hasFunct = hash%size;
    
    //return the value of the object stored into the hash
    //table ... in this case  a string value
    return (pntr+hasFunct)->get(key)->val;
    
}


//DELETE METHOD
//
//delete the value associated with the given key,
//returning the value on success or null if the
//key has no value.

string Hash::del(string key){
    
    // ----------    implement djb2 hash algorithm ----------//
    unsigned long hash = 5381;
    char *c;
    int itr = 0;
    while (itr < key.length()){
        c = &key[itr];
        hash = ((hash << 5) + hash) + (int)*c;
        itr++;
    }
    // -------------------------------------------------------//
    
    // OLD HASH FUNCTION
    // --> int hasFunct = (key[0]*31 - key[key.length()-1])%size; <--//
    
    //to set the boundaries within the size of the hash table
    int hasFunct = hash%size;
    
    //once the Node is located in the hash table ->
    Node* n = (pntr+hasFunct)->get(key);
    
    // -> remove the Node
    (pntr+hasFunct)->remove(key);
    
    //subtract #items in the hash table
    items --;
    return n->val;
}

//LOAD METHOD
//
//return a float value representing the
//load factor (`(items in hash map)/(size of hash map)`)
//of the data structure. Since the size of the dat structure is fixed,
//this should never be greater than 1.

float Hash::load(){
    
    //return the #items in the list / size_of_hash_t
    return ((float)items)/((float)size);
}