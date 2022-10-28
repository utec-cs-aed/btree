
#include <iostream>
#include "btree.h"
#include "tester.h"

using namespace std;

int main() {
  BTree<int>* btree = new BTree<int>(3);
  int numbers[10] = {45, 75, 100, 36, 120, 70, 11, 111, 47, 114};
  for (int i = 0; i < 10; i++) {
    btree->insert(numbers[i]);
  }

  ASSERT(btree->toString(" ") == "11 36 45 47 70 75 100 111 114 120",
         "The function insert is not working");
  ASSERT(btree->height() == 3, "The function height is not working");
  for (int i = 0; i < 10; i++) {
    ASSERT(findKey(btree->search(numbers[i]), numbers[i]),
           "The function search is not working");
  }
  ASSERT(btree->minKey() == 11, "The function minKey is not working");
  ASSERT(btree->maxKey() == 120, "The function maxKey is not working");

  btree->remove(100);
  btree->remove(111);
  btree->remove(45);

  ASSERT(btree->toString(" ") == "11 36 47 70 75 114 120",
         "The function remove is not working");
  ASSERT(btree->height() == 2, "The function height is not working");

  btree->remove(114);

  ASSERT(btree->toString(" ") == "11 36 47 70 75 120",
         "The function remove is not working");
  ASSERT(btree->height() == 2, "The function height is not working");
  ASSERT(btree->toString(" - ") == "11 - 36 - 47 - 71 - 75 - 120 - 125",
         "The function toString is not working");

  btree->insert(71);

  ASSERT(btree->toString(" ") == "11 36 47 70 71 75 120",
         "The function insert is not working");
  ASSERT(btree->height() == 3, "The function height is not working");

  btree->remove(70);

  ASSERT(btree->toString(" ") == "11 36 47 71 75 120",
         "The function remove is not working");
  ASSERT(btree->height() == 2, "The function height is not working");
  ASSERT(btree->maxKey() == 120, "The function maxKey is not working");

  btree->insert(125);

  ASSERT(btree->toString(" ") == "11 36 47 71 75 120 125",
         "The function insert is not working");
  ASSERT(btree->height() == 2, "The function height is not working");
  ASSERT(findKey(btree->search(125), 125),
         "The function search is not working");
  ASSERT(btree->toString(";") == "11;36;47;71;75;120;125",
         "The function toString is not working");

  btree->remove(75);

  ASSERT(btree->toString(" ") == "11 36 47 71 120 125",
         "The function remove is not working");
  ASSERT(btree->height() == 2, "The function height is not working");
  ASSERT(!findKey(btree->search(75), 75), "The function search is not working");
  ASSERT(btree->toString(",") == "11,36,47,71,120,125",
         "The function toString is not working");

  btree->remove(36);

  ASSERT(btree->toString(" ") == "11 47 71 120 125",
         "The function remove is not working");
  ASSERT(btree->height() == 2, "The function height is not working");
  ASSERT(btree->minKey() == 11, "The function minKey is not working");
  ASSERT(btree->maxKey() == 125, "The function maxKey is not working");
  ASSERT(!findKey(btree->search(200), 200),
         "The function search is not working");

  btree->remove(120);

  ASSERT(btree->toString(" ") == "11 47 71 125",
         "The function remove is not working");
  ASSERT(btree->height() == 2, "The function height is not working");
  ASSERT(!findKey(btree->search(40), 40), "The function search is not working");

  btree->remove(47);
  btree->remove(71);

  ASSERT(btree->toString(" ") == "11 125",
         "The function remove is not working");
  ASSERT(btree->height() == 1, "The function height is not working");

  return 0;
}