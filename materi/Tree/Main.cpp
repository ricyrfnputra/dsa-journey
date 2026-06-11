// Name     : Ricy Rifani Putra
// Nim      : A11.2025.16464
// Matery   : Tree 
#include<iostream>
using namespace std;

class Node{
    public:
    int data = 0;
    Node *left = NULL;
    Node *right = NULL;
    Node(int data){
        this->data = data;
    }
};

class Tree{
    public:
    Node *root;
    void preOrder(Node *root);
    void inOrder(Node *root);
    void postOrder(Node *root);
};

int main()
{
    // Tree insert manual
    Node *root = new Node(20);
    root->left = new Node(15);
    root->left->right = new Node(17);
    root->left->left = new Node(12);
    root->right = new Node(25);
    root->right->right = new Node(27);

    Tree pohon;
    cout << "Transversal pre order\n";
    pohon.preOrder(root);
    // 20-15-12-17-25-27
    cout << "\nTransversal in order\n";
    pohon.inOrder(root);
    // 12-15-17-20-25-27
    cout << "\nTransversal post order\n";
    pohon.postOrder(root);
    return 0;
}   

void Tree::preOrder(Node *root){
    if(root != NULL){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void Tree::inOrder(Node *root){
    if(root != NULL){
        preOrder(root->right);
        cout << root->data << " ";
        preOrder(root->right);
    }
}

void Tree::postOrder(Node *root){
    if(root != NULL){
        preOrder(root->right);
        preOrder(root->right);
        cout << root->data << " ";
    }
}