//
//  main.cpp
//  HashTable
//
//  Created by Michael Handria on 9/19/16.
//  Copyright © 2016 Michael Handria. All rights reserved.
//

#include <iostream>
#include <string>
#include "hash.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    
//------------------- TEST ------------------//
//   edit as needed to test the hash table   //
//   just rmbr that the hash table can only  //
//   take in string keys and string values   //
//-------------------------------------------//


// EXAMPLE TEST
/*---------------------------------------------*/
    Hash *t = new Hash(8);
    t->set("ferrari","ferrari");
    t->set("lambo","lambo");
    t->set("porsche", "porsche");
    t->set("honda","honda");
    t->set("mazda","mazda");
    t->set("toyota","toyota");
    
    cout << t->get("mazda") << endl;
    cout << t->get("honda") << endl;
    cout << t->load() << endl;
    
    cout << t->del("mazda") << endl;
    cout << t->load() << endl;
    return 0;
 /*---------------------------------------------*/
    
    
}
