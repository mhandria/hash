//
//  list.hpp
//  HashTable
//
//  Created by Michael Handria on 9/19/16.
//  Copyright © 2016 Michael Handria. All rights reserved.
//

#ifndef list_hpp
#define list_hpp

#include <stdio.h>
#include <string>

using namespace std;

//structure to contain the values for the linked list
struct Node{
    
    //the Node will hold a key
    string key;
    
    //the value of the object
    string val;
    
    //will have a pointer to the next linked object(Node)
    Node* next;
};


//This is the single chained LinkedList class
class List{
private:
    //the head of the list (where the list starts)
    Node *head;
    int length;
public:
    
    //constructor of the List
    List();
    
    //destructor of the List
    ~List();
    
    //this method grabs the node from the linked list that
    //matches the key passed in
    Node* get(string k);
    
    //this method removes a node in a
    //collided value in the
    //hash table
    bool remove(string k);
    
    //this method will add in a Node
    //at the end of the lsit
    void append(Node* item);
    
    
};
#endif /* list_hpp */
