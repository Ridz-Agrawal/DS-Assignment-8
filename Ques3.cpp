#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node* n = new Node();
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

Node* insert(Node* root, int key){
    if(root == NULL) return newNode(key);
    if(key < root->data) root->left = insert(root->left, key);
    else if(key > root->data) root->right = insert(root->right, key);
    return root;
}

Node* findMin(Node* root){
    while(root->left != NULL) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key){
    if(root == NULL) return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node* root){
    if(root == NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root){
    if(root == NULL) return 0;
    if(root->left == NULL) return 1 + minDepth(root->right);
    if(root->right == NULL) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
    Node* root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);
    cout << "Initial tree created.\n";

    cout << "Maximum Depth of BST = " << maxDepth(root) << endl;
    cout << "Minimum Depth of BST = " << minDepth(root) << endl;

    cout << "\nDeleting 10 from BST...\n";
    root = deleteNode(root, 10);

    cout << "Maximum Depth after deletion = " << maxDepth(root) << endl;
    cout << "Minimum Depth after deletion = " << minDepth(root) << endl;

    return 0;
}
