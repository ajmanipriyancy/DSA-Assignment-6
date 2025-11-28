#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node *right, *left, *up, *down;
    Node(int val) {
        data = val;
        right = left = up = down = nullptr;
    }
};

// Function to convert a 2D matrix into 2D doubly linked list
Node* construct2DLinkedList(vector<vector<int>>& mat) {
    if (mat.empty() || mat[0].empty()) return nullptr;

    int m = mat.size();
    int n = mat[0].size();

    // Create a 2D array of Node pointers
    vector<vector<Node*>> nodes(m, vector<Node*>(n, nullptr));

    // Step 1: Create all nodes
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            nodes[i][j] = new Node(mat[i][j]);
        }
    }

    // Step 2: Connect pointers
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0)
                nodes[i][j]->left = nodes[i][j - 1];
            if (j < n - 1)
                nodes[i][j]->right = nodes[i][j + 1];
            if (i > 0)
                nodes[i][j]->up = nodes[i - 1][j];
            if (i < m - 1)
                nodes[i][j]->down = nodes[i + 1][j];
        }
    }

    // Return pointer to top-left node
    return nodes[0][0];
}

// Function to print the 2D linked list row-wise
void print2DList(Node* head) {
    Node* row = head;
    while (row) {
        Node* col = row;
        while (col) {
            cout << col->data << " ";
            col = col->right;
        }
        cout << endl;
        row = row->down;
    }
}

int main() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    Node* head = construct2DLinkedList(mat);

    cout << "\n2D Doubly Linked List (row-wise display):\n";
    print2DList(head);

    return 0;
}
