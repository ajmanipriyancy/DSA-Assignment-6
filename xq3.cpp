#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

// Function to insert node at end
void insertEnd(Node*& head, int val) {
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

// Function to reverse every group of k nodes
Node* reverseInGroups(Node* head, int k) {
    if (!head) return nullptr;

    Node* curr = head;
    Node* newHead = nullptr;
    Node* nextNode = nullptr;
    int count = 0;

    // Reverse first k nodes
    while (curr && count < k) {
        nextNode = curr->next;
        curr->next = curr->prev;
        curr->prev = nextNode;
        newHead = curr; // Update new head
        curr = nextNode;
        count++;
    }

    // Now 'head' is the last node of the reversed group
    // 'curr' points to (k+1)th node (start of next group)
    if (curr != nullptr) {
        Node* rest = reverseInGroups(curr, k);
        head->next = rest;
        if (rest != nullptr)
            rest->prev = head;
    }

    return newHead;
}

// Function to print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main Function
int main() {
    Node* head = nullptr;
    int n, k, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter list elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertEnd(head, val);
    }

    cout << "Enter group size k: ";
    cin >> k;

    cout << "\nOriginal list:\n";
    printList(head);

    head = reverseInGroups(head, k);

    cout << "\nReversed in groups of " << k << ":\n";
    printList(head);

    return 0;
}
