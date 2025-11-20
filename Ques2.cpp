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

    if(key < root->data)
        root->left = insert(root->left, key);
    else if(key > root->data)
        root->right = insert(root->right, key);

    return root;
}

Node* searchRec(Node* root, int key){
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return searchRec(root->left, key);
    else
        return searchRec(root->right, key);
}

Node* searchNonRec(Node* root, int key){
    Node* temp = root;
    while(temp != NULL){
        if(temp->data == key) 
            return temp;
        else if(key < temp->data) 
            temp = temp->left;
        else 
            temp = temp->right;
    }
    return NULL;
}

int maxElement(Node* root){
    if(root == NULL){
        cout << "Tree empty!" << endl;
        return -1;
    }
    while(root->right != NULL)
        root = root->right;
    return root->data;
}

int minElement(Node* root){
    if(root == NULL){
        cout << "Tree empty!" << endl;
        return -1;
    }
    while(root->left != NULL)
        root = root->left;
    return root->data;
}

Node* inorderSuccessor(Node* root, Node* target){
    if(target == NULL) return NULL;

    Node* succ = NULL;
    while(root != NULL){
        if(target->data < root->data){
            succ = root;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* target){
    if(target == NULL) return NULL;

    Node* pred = NULL;
    while(root != NULL){
        if(target->data > root->data){
            pred = root;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return pred;
}

int main() {
    Node* root = NULL;

    int elements[] = {20, 10, 30, 5, 15, 25, 35};
    for(int x : elements)
        root = insert(root, x);

    cout << "Min element = " << minElement(root) << endl;
    cout << "Max element = " << maxElement(root) << endl;

    Node* target = searchRec(root, 10);

    if(target){
        Node* succ = inorderSuccessor(root, target);
        Node* pred = inorderPredecessor(root, target);

        cout << "Inorder successor of 10 = ";
        if(succ) cout << succ->data << endl;
        else cout << "None" << endl;

        cout << "Inorder predecessor of 10 = ";
        if(pred) cout << pred->data << endl;
        else cout << "None" << endl;
    }

    return 0;
}
