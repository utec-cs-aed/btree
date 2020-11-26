#ifndef BTree_H
#define BTree_H

#include <iostream>

#include "node.h"

using namespace std;

template <typename TK>
class BTree
{
private:
    Node<TK> *root;
    int M;
public:
    BTree(int _M) : M(_M), root(nullptr) {}

    bool search(TK key){
        if(root == nullptr) return false;        
        return search(root, key);
    }

    void display(){
        display(root);
    }

    void insert(TK key){
        if(root == nullptr){
            root = new Node<TK>(M);
            root->keys[0] = key;
            root->count++;
        } else {            
            if(root->count == M - 1)//is full
            {
                Node<TK>* parent = new Node<TK>(M);
                parent->children[0] = root;
                parent->split(0);
                if(key > parent->keys[0])
                    insert(parent->children[1], key);
                else
                    insert(parent->children[0], key);
                root = parent;
            }
        }
    }
    
    //TODO
    int height();//altura del arbol
    TK minValue();//minimo valor del arbol
    TK maxValue();//maximo valor del arbol
    int size();//retornar el total de elementos insertados
    void remove(TK key);//eliminar el key del arbol
    ~BTree();//liberar memoria

private:    

    bool search(Node<TK>* node, TK key){
        int i = 0;        
        while(i < node->count && key > node->keys[i]) i++;
        if(node->keys[i] == key) 
            return true;
        else if(node->leaf)
            return false;     
        else        
            return search(node->children[i], key);
    }

    void display(Node<TK>* node){
        if(node == nullptr) return;

        for (int i = 0; i < node->count; i++)
        {   
            if(!node->leaf)
                display(node->children[i]);
            cout<<node->keys[i]<<", ";
        }  
        if(!node->leaf)      
            display(node->children[node->count - 1]);
    }

    void insert(Node<TK>* node, TK key){
        if(node->leaf){//es hoja
            int i = node->count - 1;
            while(i >= 0 && node->keys[i] > key) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i+1] = key;
            node->count++;
        } else { // es interno
            int i = node->count - 1;
            while(i >= 0 && node->keys[i] > key)  i--;            
            if(node->children[i+1]->count == M - 1){
                node->split(i+1);
                if(key > node->keys[i+1])   i++;
            }
            insert(node->children[i+1], key);
        }
    }
};

#endif