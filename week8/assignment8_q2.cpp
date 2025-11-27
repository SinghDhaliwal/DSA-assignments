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

Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    else return searchRec(root->right, key);
}

Node* searchIter(Node* root, int key) {
    while (root) {
        if (key == root->data) return root;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

Node* minNode(Node* root) {
    if (!root) return NULL;
    while (root->left) root = root->left;
    return root;
}

Node* maxNode(Node* root) {
    if (!root) return NULL;
    while (root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* cur = root;
    Node* succ = NULL;
    while (cur && cur->data != key) {
        if (key < cur->data) {
            succ = cur;
            cur = cur->left;
        } else cur = cur->right;
    }
    if (!cur) return NULL;
    if (cur->right) return minNode(cur->right);
    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* cur = root;
    Node* pred = NULL;
    while (cur && cur->data != key) {
        if (key > cur->data) {
            pred = cur;
            cur = cur->right;
        } else cur = cur->left;
    }
    if (!cur) return NULL;
    if (cur->left) return maxNode(cur->left);
    return pred;
}

int main() {
    Node* root = NULL;
    int a[] = {20, 10, 30, 5, 15, 25, 40};


    for (int i = 0; i < 7; i++)
        root = insert(root, a[i]);

    Node* s1 = searchRec(root, 15);
    Node* s2 = searchIter(root, 25);
    cout << (s1 ? s1->data : -1) << endl;
    cout << (s2 ? s2->data : -1) << endl;

    cout << minNode(root)->data << endl;
    cout << maxNode(root)->data << endl;

    Node* succ = inorderSuccessor(root, 20);
    Node* pred = inorderPredecessor(root, 20);
    cout << (succ ? succ->data : -1) << endl;
    cout << (pred ? pred->data : -1) << endl;
}
