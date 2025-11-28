#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to split circular linked list into two halves
void splitCircularList(Node* head, Node** head1_ref, Node** head2_ref) {
    if (head == nullptr)
        return;

    Node* slow = head;
    Node* fast = head;

    // Move fast by two and slow by one
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // If even number of nodes, move fast one step further
    if (fast->next->next == head)
        fast = fast->next;

    // Set heads for two halves
    *head1_ref = head;
    if (head->next != head)
        *head2_ref = slow->next;

    // Make first half circular
    fast->next = slow->next;
    slow->next = head;
}

// Function to print a circular linked list
void printList(Node* head) {
    if (!head)
        return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Function to create a circular linked list
Node* createCircularList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    Node* head = new Node(vals[0]);
    Node* temp = head;
    for (int i = 1; i < vals.size(); i++) {
        temp->next = new Node(vals[i]);
        temp = temp->next;
    }
    temp->next = head; // Make circular
    return head;
}

int main() {
    // Example: 1 → 2 → 3 → 4 → 5 → back to 1
    vector<int> vals = {1, 2, 3, 4, 5};
    Node* head = createCircularList(vals);

    Node *head1 = nullptr, *head2 = nullptr;

    splitCircularList(head, &head1, &head2);

    cout << "First half: ";
    printList(head1);

    cout << "Second half: ";
    printList(head2);

    return 0;
}
