//
//  hash.hpp
//  HashTable
//
//  Created by Michael Handria on 9/19/16.
//  Copyright © 2016 Michael Handria. All rights reserved.
//

#ifndef hash_hpp
#define hash_hpp


#include <stdio.h>
#include <string>
#include "list.hpp"

using namespace std;
/*

 
 boolean set(key, value):
 
 stores the given key/value pair in
 the hash map. Returns a boolean value
 indicating success / failure of the operation.
 
 get(key):
 
 return the value associated
 with the given key, or null if no value is set.
 
 delete(key):
 
 delete the value associated with the given key,
 returning the value on success or null if the
 key has no value.
 
 float load():
 
 return a float value representing the
 load factor (`(items in hash map)/(size of hash map)`)
 of the data structure. Since the size of the dat structure is fixed,
 this should never be greater than 1.
 */


class Hash{
    
private:
    
    //this will be the size of the hash table
    int size;
    
    //this shows the number of item in the list
    int items;
    
    //this will be used to point to the Linked list
    //stored in each Hash Table's index
    List* pntr;
public:
    
    //construct the hash table
    Hash(int s);
    
    //destruct the hash table;
    ~Hash();
    
    //set the object into the hash table
    bool set(string key, string value);
    
    //get the value of the give key from
    //the hash table
    string get(string key);
    
    //delete an item in the hash table
    string del(string key);
    
    //find the #items/size_of_hash_t
    float load();
    
    
    
};

#endif /* hash_hpp */
