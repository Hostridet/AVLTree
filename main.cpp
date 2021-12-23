#include <iostream>
#include "Method.h"

using namespace std;
int main() {
    AVLTree t;
    AVLTree t1;
    // Проверка сравнения
    t.add(2);
    t.add(4);
    t.add(1);
    t.add(0);

    t1.add(4);
    t1.add(3);
    t1.add(2);
    t1.add(5);

    cout << "Compared: " << t.compare(t1);
    // end

    // Добавление
    AVLTree test1;

    for(int i = 0; i <=10; i++)
    {
        test1.add(10-i);
    }
    test1.add(7);
    test1.add(10);
    test1.printTree();

    return 0;
}
