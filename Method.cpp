#include "Method.h"
#include "iostream"
#define COUNT 3

using namespace std;

//Public functions
AVLTree::AVLTree() {
    root = nullptr;
}

void AVLTree::add(int x) {
    root = insert(root, x);
}

void AVLTree::del(int x) {
    root = remove(root, x);
}

bool AVLTree::search(int x) {
    return search(x,root);
}

void AVLTree::deAll() {
    root = removeall(root);
}

void AVLTree::printTree() {
    if (root != nullptr)
        print(root, 0);
    else cout << "Пустое дерево!" << endl;
}

void AVLTree::print(node root, int space) {
    if (root != nullptr) {

        space += COUNT;
        print(root->right, space);
        cout << endl;
        // count
        for (int i = COUNT; i < space; i++)
            cout << " ";
        cout << root->data << "\n";

        // Process left child
        print(root->left, space);
    }
}
bool AVLTree::compare(AVLTree &sec) {
    return compareHelp(root, sec.getRoot());
}

AVLTree::node AVLTree::getRoot() {
    return root;
}

//Private functions
int AVLTree::height(node p) {
    return p ? p -> height : 0;
}

int AVLTree::bfactor(node p) {
    return height(p -> right) - height(p -> left);
}

void AVLTree::fixheight(node p) {
    int hl = height(p->left);
    int hr = height(p->right);
    p -> height = (hl > hr ? hl : hr) + 1;
}

AVLTree::node AVLTree::rotateRight(node p) {
    //cout << "поворот вправо" << endl;
    node q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

AVLTree::node AVLTree::rotateLeft(node q) {
    //cout << "поворот влево" << endl;
    node p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

bool AVLTree::compareHelp(Node *a, Node *b) {
    if (((a != nullptr) && (b == nullptr)) || ((a == nullptr) && (b != nullptr)))
        return false;
    if ((a != nullptr) && (b != nullptr))
        return compareHelp(a->left, b->left) && compareHelp(a->right, b->right);
    return true;
}
AVLTree::node AVLTree::balance(node p) {
    fixheight(p);
    if (bfactor(p) == 2) {
//             cout << "большой поворот";
        if (bfactor(p->right) < 0)
            p->right = rotateRight(p->right);
        return rotateLeft(p);
    }
    if (bfactor(p) == -2) {
//            cout << "большой поворот";
        if (bfactor(p->left) > 0)
            p->left = rotateLeft(p->left);
        return rotateRight(p);
    }
    return p; // балансировка не нужна
}

AVLTree::node AVLTree::insert(node p, type k) {
    if( !p ) return new Node(k);
    if (k < p->data)
        p->left = insert(p->left,k);
    if (k > p->data)
        p->right = insert(p->right,k);
    return balance(p);
}

AVLTree::node AVLTree::findmin(node p) {
    return p->left ? findmin(p->left) : p;
}

AVLTree::node AVLTree::removemin(node p) {
    if (p->left == 0)
        return p->right;
    p->left = removemin(p->left);
    return balance(p);
}

AVLTree::node AVLTree::remove(node p, type k) {
    if (!p) return 0;
    if (k < p->data)
        p->left = remove(p->left,k);
    else if( k > p->data )
        p->right = remove(p->right,k);
    else {                        //  k == p->key
        node q = p->left;
        node r = p->right;
        delete p;
        if( !r ) return q;
        node min = findmin(r);
        min->right = removemin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}

AVLTree::node AVLTree::removeall(node p) {
    if (!p) return 0;
    while (p->left != 0 && p->right != 0) {
        p->left = remove(p->left,p->left->data);
        p->right = remove(p->right,p->right->data);
    }
    remove(p, p->data);
    return nullptr;
}


AVLTree::node AVLTree::search(type x, node p) {
    if (p == nullptr) {
        return nullptr; // эл-та нет
    } else {
        if (x < p->data) {
            search(x, p->left);
        } else {
            if (x > p->data) {
                search(x, p->right);
            } else {
                return p; // эл-т найден
            }
        }
    }
}