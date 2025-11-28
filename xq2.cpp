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

struct CNode {
    int data;
    CNode* next;
    CNode(int val) {
        data = val;
        next = nullptr;
    }
};

// -----------------------------
// Doubly Linked List Functions
// -----------------------------
void insertDNode(DNode*& head, int val) {
    DNode* newNode = new DNode(val);
    if (!head) {
        head = newNode;
        return;
    }
    DNode* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteEvenDNodes(DNode*& head) {
    DNode* curr = head;
    while (curr) {
        if (curr->data % 2 == 0) {
            DNode* toDelete = curr;
            if (curr->prev)
                curr->prev->next = curr->next;
            else
                head = curr->next; // deleting head

            if (curr->next)
                curr->next->prev = curr->prev;

            curr = curr->next;
            delete toDelete;
        } else {
            curr = curr->next;
        }
    }
}

void printDList(DNode* head) {
    cout << "Doubly Linked List: ";
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// -----------------------------
// Circular Singly Linked List Functions
// -----------------------------
void insertCNode(CNode*& head, int val) {
    CNode* newNode = new CNode(val);
    if (!head) {
        head = newNode;
        head->next = head;
        return;
    }
    CNode* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

void deleteEvenCNodes(CNode*& head) {
    if (!head)
        return;

    // Handle even head nodes first
    while (head && head->data % 2 == 0) {
        // If only one node and it's even
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        // Find last node
        CNode* last = head;
        while (last->next != head)
            last = last->next;

        CNode* toDelete = head;
        head = head->next;
        last->next = head;
        delete toDelete;
    }

    if (!head) return;

    // Now handle non-head nodes
    CNode* curr = head;
    while (curr->next != head) {
        if (curr->next->data % 2 == 0) {
            CNode* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
        } else {
            curr = curr->next;
        }
    }
}

void printCList(CNode* head) {
    if (!head) {
        cout << "Circular Linked List: (empty)" << endl;
        return;
    }
    cout << "Circular Linked List: ";
    CNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// -----------------------------
// Main Function
// -----------------------------
int main() {
    // Create Doubly Linked List
    DNode* dHead = nullptr;
    insertDNode(dHead, 10);
    insertDNode(dHead, 15);
    insertDNode(dHead, 20);
    insertDNode(dHead, 25);
    insertDNode(dHead, 30);

    cout << "Before deletion:\n";
    printDList(dHead);
    deleteEvenDNodes(dHead);
    printDList(dHead);

    // Create Circular Singly Linked List
    CNode* cHead = nullptr;
    insertCNode(cHead, 12);
    insertCNode(cHead, 17);
    insertCNode(cHead, 22);
    insertCNode(cHead, 35);
    insertCNode(cHead, 40);

    cout << "\nBefore deletion:\n";
    printCList(cHead);
    deleteEvenCNodes(cHead);
    printCList(cHead);

    return 0;
}
