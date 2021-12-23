#include <iostream>
using namespace std;

class AVLTree {

    typedef int type;

    struct Node {
        int data;
        int height;
        Node* left;
        Node* right;
        int counter = 1;
        Node(type k) { data = k; left = right = 0; height = 1; }
    };

    typedef struct Node *node;

    node root;

    int height(node p);
    int bfactor(node p);
    void fixheight(node p);
    node rotateRight(node p);
    node rotateLeft(node q);
    node balance(node p);
    node insert(node p, int k);
    node findmin(node p);
    node removemin(node p);
    node remove(node p, int k);
    node removeall(node p);
    node search (int x, node p);
    void print(node root, int space);
    bool compareHelp(Node *a, Node *b);
public:
    //Конструктор
    AVLTree();
    //Добавление элемента
    void add(int x);
    //Удаление элемента
    void del(int x);
    //Поиск элемента
    bool search (int x);
    //Удаление всего
    void deAll();
    //Печать
    void printTree();
    node getRoot ();
    bool compare(AVLTree &sec);
};
