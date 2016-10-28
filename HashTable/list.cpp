//
//  list.cpp
//  HashTable
//
//  Created by Michael Handria on 9/19/16.
//  Copyright © 2016 Michael Handria. All rights reserved.
//

#include "list.hpp"

//CONSTRUCTOR
List::List(){
    
    //allocate and initialize
    //the head of the list
    head = new Node;
    
    //initialize
    //the length of the list
    length = 0;
    
}


//DECONSTRUCTOR
List::~List(){
    
    //pointer to Node being deleted
    Node* delhead = head;
    
    //this pointer will serve as a
    //place holder to prevent being
    //"lost" in the linked list
    Node* holder = head;
    
    //while loop that iterates through
    //the list until you delete everything
    while(delhead){
        
        //set to the delete pointer to the
        //place holder
        delhead = holder;
        
        //advance the place holder to the
        //next node
        holder = delhead->next;
        
        //if the delete pointer contains a
        //value
        if(delhead){
            
            //reallocate the next Node link
            delete delhead->next;
            //reallocate the Node back to
            //memory pool
            delete delhead;
        }
    }
}

//GET METHOD
Node* List::get(string k){
    
    //this pointer will allow iteration
    //through the linked list
    Node* itr = head;
    
    //while the pointer doesn't point
    //to NULL, keep iterating through
    while(itr){
        
        //if the key is found that matches
        //the desired key then return the
        //Node
        if(itr->key == k){
            return itr;
        }
        
        //else iterate through the next
        //Node
        else{
            itr = itr->next;
        }
    }
    
    //return a NULL if no key is found
    return NULL;
}

//REMOVE METHOD
bool List::remove(string k){
    
    //if the head of the list has
    //the matching key then unlinked
    //the head and reallocate it back
    if(head->key == k){
        
        //store the address of head
        Node *itr = head;
        
        //set head to new Node
        head = head->next;
        
        //reallocate Node to memory pool
        delete itr;
        return true;
    }
    
    //Node pointer used to iterate
    //through linked list
    Node* itr = head;
    
    //This Node pointer will point
    //to the next Node
    Node* n = head->next;
    
    //itrate through the
    //list until you find a key match
    while(itr){
        
        //if the key is matched then
        //set the current's Node next to
        //the next's next Node and delete
        //the next node
        if(n->key == k){
            if(n->next == NULL){
                itr->next = NULL;
                delete n;
                return true;
            }
            else{
                itr->next = n->next;
                delete n;
                return true;
            }
        }
        
        //if the key has not been found
        //iterate through the node until
        //you find null;
        itr = n;
        n = itr->next;
    }
    return false;
}


//ADD METHOD
void List::append(Node* item){
    
    //set the item's next Node to NULL
    //because item will be added to the
    //end of the List
    item->next = NULL;
    
    //ust this pointer to iterate
    //through the list;
    Node * itr = head;
    
    //if the length of the list
    //is 0 then make the item
    //the head of the list
    if(length == 0){
        head = item;
        
        //increment the length of
        //the list
        length ++;
        
        //break through from the list
        return;
    }
    
    //else iterate through the list and
    //until you find the end and then
    //append the item to the list
    else{
        
        //list iteration loop
        while(itr->next){
            itr = itr->next;
        }
        
        //set the next of the last node
        //to the item being added
        itr->next = item;
        
        //increment the length of the list
        length++;
    }
}
