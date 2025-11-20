#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

bool isBSTUtil(Node* root, int minVal, int maxVal){
    if(root == NULL) return true;

    if(root->data <= minVal || root->data >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root){
    return isBSTUtil(root, -1000000, 1000000);
}

int main() {
    Node* root = new Node{10, NULL, NULL};
    root->left = new Node{5, NULL, NULL};
    root->right = new Node{20, NULL, NULL};

    root->left->left = new Node{2, NULL, NULL};
    root->left->right = new Node{8, NULL, NULL};

    root->right->left = new Node{15, NULL, NULL};
    root->right->right = new Node{25, NULL, NULL};

    if(isBST(root))
        cout << "The given tree IS a BST" << endl;
    else
        cout << "The given tree is NOT a BST" << endl;

    return 0;
}
