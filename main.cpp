
#include <iostream>
#include "btree.h"
using namespace std;

int main(int argc, char const *argv[]){
    BTree<int> *btree = new BTree<int>(4);
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        btree->insert(val);
    }

    int option = atoi(argv[1]);
    switch (option)
    {
        case 1:
            btree->display();
            break;
        case 2:
            cout << btree->height();
            break;
        case 3:
            cout << btree->minValue();
            break;
        case 4:
            cout << btree->maxValue();
            break;
        case 5:
            cin>>val;
            cout << btree->search(val);
            break;    
        case 6:
            cin>>val;
            btree->remove(val);
            cin>>val;
            btree->remove(val);
            btree->display();
            break;
    }
    return 0;
}