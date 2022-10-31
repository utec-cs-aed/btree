#ifndef BTree_H
#define BTree_H
#include <iostream>
#include "node.h"

using namespace std;

template <typename TK>
class BTree {
 private:
  Node<TK>* root;
  int M;  // grado u orden del arbol

 public:
  BTree(int _M) : root(nullptr), M(_M) {}

  bool search(TK key);
  void insert(TK key);
  void remove(TK key);
  int height();
  string toString(const string& sep);  // inorder

  TK minKey();  // minimo valor de la llave en el arbol
  TK maxKey();  // maximo valor de la llave en el arbol
  ~BTree();     // liberar memoria
};

#endif
