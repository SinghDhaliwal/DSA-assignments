#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) { data = x; left = right = NULL; }
};

Node* insert(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->data) root->left = insert(root->left, x);
    else if (x > root->data) root->right = insert(root->right, x);
    return root;
}

Node* minNode(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        } else if (!root->left) {
            Node* t = root->right;
            delete root;
            return t;
        } else if (!root->right) {
            Node* t = root->left;
            delete root;
            return t;
        } else {
            Node* t = minNode(root->right);
            root->data = t->data;
            root->right = deleteNode(root->right, t->data);
        }
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + (l > r ? l : r);
}

int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    return 1 + (l < r ? l : r);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }
    inorder(root);
    cout << endl;

    int del;
    cin >> del;
    root = deleteNode(root, del);
    inorder(root);
    cout << endl;

    cout << maxDepth(root) << endl;
    cout << minDepth(root) << endl;
}
