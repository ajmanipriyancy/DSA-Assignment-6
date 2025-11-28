#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

bool isCircular(Node* head) {
    if (head == nullptr)
        return true; 

    Node* temp = head->next;

   
    while (temp != nullptr && temp != head)
        temp = temp->next;

    return (temp == head);
}

void printList(Node* head, int count = 10) {
    Node* temp = head;
    while (temp != nullptr && count--) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
  
    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);


    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = head2; 

    cout << "List 1: ";
    printList(head1);
    cout << (isCircular(head1) ? "Circular" : "Not Circular") << endl;


    cout << "\nList 2: ";
    printList(head2);
    cout << (isCircular(head2) ? "Circular" : "Not Circular") << endl;

    return 0;
}
