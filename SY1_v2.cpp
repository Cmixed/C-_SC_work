#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class List
{
    public:
        int _data;
        int _xn;
        List *next;
        List() : _data(0), _xn(0), next(nullptr) { };
        List(int data, int xn) : _data(data), _xn(xn), next(NULL) { };
        List operator*(const List &list) {
            return List(this->_data*list._data, this->_xn*list._xn);
        }
};

List* AppendNode(List *head);
List* AddNode(List *head, List &temp);
void DisplayNode(List *head);
void DeleteMemory(List *head);
List* MutiplyList(List *head1, List *head2, List *head3, int ALength, int BLength);
void DeleteNode(List *head, int count);
List* NextNode(List *pointer);
List* NextNode(List *pointer, int count);
List* ListMerge(List *head, int length);

int main()
{
//  Chap01    处理输入部分
    int ALength = 0, BLength = 0;
    cout << "Input A(x) and B(x) number" << endl;
    cin >> ALength >> BLength;
    List *head1 = NULL, *head2 = NULL;
    cout << "Input A(x) //Format (coefficient)X^(power exponent) one by one" << endl;
    for (int i = 0; i < ALength; i++) {
        head1 = AppendNode(head1);
        cin.ignore(1024, '\n');
    }
    // cout << "Check your input!!!" << endl;
    // DisplayNode(head1);

    cout << "Input B(x) //Format (coefficient)X^(power exponent) one by one" << endl;
    for (int i = 0; i < BLength; i++) {
        head2 = AppendNode(head2);
        cin.ignore(1024, '\n');
    }
    // cout << "Check your input!!!" << endl;
    // DisplayNode(head2);

// Chap02   处理链表之间的多项式乘法

    List *head3 = nullptr;
    head3 = MutiplyList(head1, head2, head3, ALength, BLength);
    // cout << "RAW:   " << endl;
    // DisplayNode(head3);

    head3 = ListMerge(head3, ALength+BLength+1);
    cout << "M(x) = A(x) * B(x) :    " << endl;
    DisplayNode(head3);


// Chap03   善后，释放内存空间

    DeleteMemory(head1);
    DeleteMemory(head2);
    DeleteMemory(head3);

    return 0;
}

// MutiplyList() 正确无误
List* MutiplyList(List *head1, List *head2, List *head3, int ALength, int BLength) {
    List *p1 = head1, *p2 = head2, *p3 = head3;
    for (int i = 0; i < ALength; i++) {
        for (int j = 0; j < BLength; j++) {
            List temp = List(p1->_data*p2->_data, p1->_xn+p2->_xn);
            head3 = AddNode(head3, temp);
            p2 = p2->next;
        }
        p1 = p1->next;
        p2 = head2;
    }
    // cout << "In MutiplyList :" << endl;
    // DisplayNode(head3);
    
    return head3;
}

List* ListMerge(List *head, int length) {
// 先冒泡排序 正确无误
    List *p1 = head, *p2 = head->next;
    if (p2->next == NULL) { return head; }
    for (int i=0; i<length-1; i++) {
        for (int j=0; j<length-i-1; j++) {
            if (p1->_xn > p2->_xn) {
                List temp(p1->_data, p1->_xn);
                p1->_data = p2->_data;
                p1->_xn = p2->_xn;
                p2->_data = temp._data;
                p2->_xn = temp._xn;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        p1 = head;
        p2 = head->next;
    }
    
    // p1 = head; p2 = head->next;
    // auto MergeNode = [&] (List *p1, List *p2 ) -> List* {
    //     p1->_data = p1->_data+p2->_data;
    //     p1->next = p2->next;
    //     free(p2);
    //     return p1;
    // };

    // p1 = head; p2 = head->next;
    // for (int i = 0; i < length; i++) {
    //     if (p1->_xn == p2->_xn) {
    //         p1 = MergeNode(p1, p2);
    //         p2 = p1->next;
    //         ++i;
    //     }
    // }
    
    p1 = head; p2 = head->next;
    
    // cout << "After Sort:   " << endl;
    // DisplayNode(head);


    List *temp = NULL;
    for (int i = 0; i < length; i++) {
        if (p1->_xn == p2->_xn) {
            temp = p2;
            p1->_data = p1->_data + p2->_data;
            p1->next = p2->next;
            p2 = p2->next;
            free(temp);
        } else {
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    return head;
}


List* AppendNode(List *head) {
    List *p = NULL, *pr = head;
    int data, xn;
    p = (struct List *)malloc(sizeof(struct List));
    if (p == NULL) { exit(0); }
    if (head == NULL) {
        head = p;
    }else {
        while (pr->next != NULL) {
            pr = pr->next;
        }
        pr->next = p;

    }
    scanf("%d%*c%*c%d", &data, &xn);
    // cout << "Line57" << data << "  " << xn << endl;
    p->_data = data;
    p->_xn = xn;
    p->next = NULL;
    return head;
}

List* AddNode(List *head, List &temp) {
    List *p = NULL, *pr = head;
    p = (struct List *)malloc(sizeof(struct List));
    if (p == NULL) { exit(0); }
    p->_data = temp._data;
    p->_xn = temp._xn;
    p->next = NULL;
    if (head == NULL) {
        head = p;
    }else {
        while (pr->next != NULL) {
            pr = pr->next;
        }
        pr->next = p;
    }
    return head;
}


List* NextNode(List *pointer) {
    List *p = pointer;
    if (p->next != NULL) {
        p = p->next;
    } else
        cout << "NO NextNode!!!" << endl;
    return p;
}

List* NextNode(List *pointer, int count) {
    List *p  = pointer;
    while (count) {
        p = p->next;
        --count;
    }
    return p;
}

void DisplayNode(List *head) {
    List *p = head;
    int count = 1;
    while (p != NULL)
    {
        cout << count << " :: " << p->_data << "X^" << p->_xn << endl;
        p = p->next;
        ++count;
    }
    
}

void DeleteMemory(List *head) {
    List *p = head, *pr = NULL;
    while (p != NULL) {
        pr = p;
        p = p->next;
        free(pr);
    }
}

void DeleteNode(List *head, int count) {
    int flag = 0;
    List *p = head;
    while (flag != count ) {
        ++flag;
        p = p->next;
    }
    if (flag == count) {
        free(p);
    }
}