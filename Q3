#include <bits/stdc++.h>
using namespace std;


struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) {
        data = val;
        prev = next = nullptr;
    }
};


int sizeOfDoubly(DNode* head) {
    int count = 0;
    DNode* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

struct CNode {
    int data;
    CNode* next;
    CNode(int val) {
        data = val;
        next = nullptr;
    }
};

int sizeOfCircular(CNode* head) {
    if (!head) return 0;
    int count = 0;
    CNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}


int main() {
  
    DNode* d1 = new DNode(10);
    DNode* d2 = new DNode(20);
    DNode* d3 = new DNode(30);
    d1->next = d2;
    d2->prev = d1;
    d2->next = d3;
    d3->prev = d2;

    cout << "Size of Doubly Linked List: " << sizeOfDoubly(d1) << endl;

  
    CNode* c1 = new CNode(5);
    CNode* c2 = new CNode(15);
    CNode* c3 = new CNode(25);
    c1->next = c2;
    c2->next = c3;
    c3->next = c1;  

    cout << "Size of Circular Linked List: " << sizeOfCircular(c1) << endl;

    return 0;
}
