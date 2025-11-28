#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node* random;
    Node(int val) {
        data = val;
        prev = next = random = nullptr;
    }
};

// Function to print list along with random pointers
void printList(Node* head) {
    Node* temp = head;
    cout << "Node\tRandom\n";
    while (temp) {
        cout << temp->data << "\t";
        if (temp->random)
            cout << temp->random->data;
        else
            cout << "NULL";
        cout << endl;
        temp = temp->next;
    }
}

// Function to detect and correct one wrong random pointer
void correctRandomPointer(Node* head, unordered_map<int, int> expectedRandom) {
    // Map from data → Node pointer
    unordered_map<int, Node*> nodeMap;
    Node* temp = head;
    while (temp) {
        nodeMap[temp->data] = temp;
        temp = temp->next;
    }

    // Find mismatch and correct it
    temp = head;
    while (temp) {
        int expected = expectedRandom[temp->data];
        if (temp->random->data != expected) {
            cout << "\nIncorrect random pointer found at node " << temp->data
                 << " (was pointing to " << temp->random->data << ")\n";
            temp->random = nodeMap[expected];
            cout << "Corrected to point to node " << expected << ".\n";
        }
        temp = temp->next;
    }
}

int main() {
    // Create nodes
    Node* A = new Node(1);
    Node* B = new Node(2);
    Node* C = new Node(3);
    Node* D = new Node(4);

    // Link them (doubly)
    A->next = B;
    B->prev = A;
    B->next = C;
    C->prev = B;
    C->next = D;
    D->prev = C;

    // Assign random pointers (one is wrong)
    A->random = C; // correct
    B->random = A; // correct
    C->random = B; // ❌ wrong (should be D)
    D->random = B; // correct

    // Expected mapping: data → random data
    unordered_map<int, int> expectedRandom = {
        {1, 3}, {2, 1}, {3, 4}, {4, 2}
    };

    cout << "Before correction:\n";
    printList(A);

    correctRandomPointer(A, expectedRandom);

    cout << "\nAfter correction:\n";
    printList(A);

    return 0;
}
