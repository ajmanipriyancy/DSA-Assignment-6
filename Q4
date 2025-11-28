#include <bits/stdc++.h>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    char data;
    Node* prev;
    Node* next;
    Node(char val) {
        data = val;
        prev = next = nullptr;
    }
};


void insertAtEnd(Node*& head, char val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;


    Node* tail = head;
    while (tail->next)
        tail = tail->next;

    while (head != tail && tail->next != head) {
        if (head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

// Function to display list
void display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {
    Node* head = nullptr;
    string input;

    cout << "Enter characters (no spaces): ";
    cin >> input;


    for (char c : input)
        insertAtEnd(head, c);

    cout << "Doubly Linked List: ";
    display(head);

    if (isPalindrome(head))
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is NOT a palindrome." << endl;

    return 0;
}
