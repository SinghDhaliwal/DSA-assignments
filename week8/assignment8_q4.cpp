#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) 
    { 
        data = x; 
        left = right = NULL; 
    }
};

bool isBSTUtil(Node* root, long long minV, long long maxV) {
    if (!root) return true;
    if (root->data <= minV || root->data >= maxV) return false;
    return isBSTUtil(root->left, minV, root->data) &&
           isBSTUtil(root->right, root->data, maxV);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    cout << (isBST(root) ? "BST" : "Not BST");
}
