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

Node* createCircularList(vector<int> values) {
    if (values.empty()) return nullptr;

    Node* head = new Node(values[0]);
    Node* temp = head;

    for (int i = 1; i < values.size(); i++) {
        temp->next = new Node(values[i]);
        temp = temp->next;
    }

    temp->next = head;

    return head;
}


void displayCircularList(Node* head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

   
    cout << head->data << endl;
}


int main() {
   
    vector<int> values = {20, 100, 40, 80, 60};
    Node* head = createCircularList(values);

    cout << "Circular Linked List: ";
    displayCircularList(head);

    return 0;
}
