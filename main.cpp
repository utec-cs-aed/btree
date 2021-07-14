
#include <iostream>
#include "btree.h"
#include "tester.h"
using namespace std;

int main(){
    BTree<int> *btree = new BTree<int>(4);
    btree->insert(45);
    btree->insert(75);
    btree->insert(100);
    btree->insert(36);
    btree->insert(120);
    btree->insert(70);
    btree->insert(11);
    btree->insert(111);
    btree->insert(47);
    btree->insert(114);
    ASSERT(btree->toString(" ") == "11 36 45 47 70 75 100 111 114 120 ", 
        "The function insert is not working");
    ASSERT(btree->height() == 3, 
        "The function height is not working");

    btree->remove(100);
    btree->remove(111);
    btree->remove(45);

    ASSERT(btree->toString(" ") == "11 36 47 70 75 114 120 ", 
        "The function remove is not working");
    ASSERT(btree->height() == 2, 
        "The function height is not working");

    return 0;
}