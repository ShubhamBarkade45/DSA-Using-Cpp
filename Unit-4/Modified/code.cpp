#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

Node* deleteLeaf(Node* root, int key, bool &found,
                 bool &deleted) {
    if (root == NULL)
        return NULL;

    if (key < root->data) {
        root->left = deleteLeaf(root->left, key,
                                found, deleted);
    }
    else if (key > root->data) {
        root->right = deleteLeaf(root->right, key,
                                 found, deleted);
    }
    else {
        found = true;

        if (root->left == NULL && root->right == NULL) {
            delete root;
            deleted = true;
            return NULL;
        }

        deleted = false;
    }

    return root;
}

int main() {
    Node* root = NULL;
    int n, value, key, count;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nBST before deletion: ";
    inorder(root);

    cout << "\nHow many nodes do you want to delete? ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        cout << "\nEnter key to delete: ";
        cin >> key;

        bool found = false;
        bool deleted = false;

        root = deleteLeaf(root, key, found, deleted);

        if (!found)
            cout << "Key does not exist!" << endl;
        else if (!deleted)
            cout << "Node is not a leaf node!" << endl;
        else
            cout << "Leaf node deleted successfully!" << endl;

        cout << "Current BST: ";
        inorder(root);
        cout << endl;
    }

    cout << "\nBST after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
