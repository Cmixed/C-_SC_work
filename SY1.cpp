#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class List {
    public:
        int _data;
        int _xn;
        List *next;

        List() = default;
        List(int data, int xn) : _data(data), _xn(xn) {
            next = NULL;
        }
        ~List() { }
        List operator*(const List &list) {
            return List(this->_data*list._data, this->_xn*list._xn);
        }
        List* addNode(List *headpointer, int data, int xn);
        void displayList(List *headpointer);
        void deleteMemory( List *headpointer);
};
List* input(List *headpointer, int length);
// List* multi_pylist(List A, List B);


int main()
{
// 输入部分
    int ALength = 0, BLength = 0;
    cout << "Input A(x) and B(x) number" << endl;
    cin >> ALength >> BLength;
    List *head1 = NULL, *head2 = NULL;
    head1->next = NULL; head2->next = NULL;
    cout << "Input A(x) //Format (coefficient)X^(power exponent)+" << endl;
    head1=input(head1, ALength);
    cout << "Input B(x) //Format (coefficient)X^(power exponent)+" << endl;
     input(head2, BLength);
    head1->displayList(head1);


// 处理部分







    return 0;
}

List* input(List *headpointer, int length) {
    int data = 0, xn = 0;
    char c = 0;
    for (int i=0; i<length; i++) {
        cout << "A(x):  ";
        cin >> data >> c >> c >> xn >> c;
        // scanf("%d%*c%*c%d%*c", data, xn);
        headpointer=headpointer->addNode(headpointer, data, xn);
    }
    return headpointer;
}

// List* multi_pylist(List A, List B) {
//     List *p = A.next;
//     return p;
// }

// List 类 实现代码
List* List::addNode(List *headpointer, int data, int xn) {
    List *p = NULL, *head = headpointer, *p1 = headpointer;
    p = new List(data, xn); 
    if(p == NULL) { exit(0); }
    while (p1->next != NULL) {
        p1 = p1->next;
    }
    p1->next = p;
    p->next = NULL;
    return headpointer;
}

void List::displayList(List *headpointer) {
    List *p1 = headpointer->next;
    while (p1 != NULL)
    {
        cout << p1->_data << "X^" << p1->_xn << endl;
        p1 = p1->next;
    }
    
}

void List::deleteMemory(List *headpointer) {
    List *p1 = headpointer, *p = NULL;
    while (p1 != NULL)
    {
        p = p1;
        p1 = p1->next;
        delete p;
    }
}