#ifndef NODE_H
#define NODE_H

using namespace std;

template <typename TK>
struct Node {
    TK* keys;     
    Node** children;
    int count;//total de keys
    bool leaf;

    Node():keys(nullptr), children(nullptr), count(0) {}
    Node(int M){
        keys = new TK[M-1];
        children = new Node<TK>*[M];
        count = 0;
        leaf = true;
    }   

    void split(int child){
        //TODO: dividir el hijo de la posicion "child"
    }

    void killSelf(){
        // TODO: borrar el nodo recursivamente
    }
};

#endif