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
    
    Node *insertBinaryRoot(Node *root, int nilai);
    void preOrder(Node *root);
    void inOrder(Node *root);
    void postOrder(Node *root);
    int heightNode(Node *root);
    void levelOrder(Node *root);
    void PrintCurrentLevel(Node *root, int level);  
    void inOrderAritmatika(NodeAritmatika *root);
};

class NodeAritmatika{
    public:
    char data = ' ';
    NodeAritmatika *left = NULL;
    NodeAritmatika *right = NULL;
    NodeAritmatika(char data){
        this->data = data;
    }
};

int main()
{
    // Tree insert manual
    // Node *root = new Node(20);
    // root->left = new Node(15);
    // root->left->right = new Node(17);
    // root->left->left = new Node(12);
    // root->right = new Node(25);
    // root->right->right = new Node(27);

    // Tree pohon;
    // cout << "Transversal pre order\n";
    // pohon.preOrder(root);
    // // 20-15-12-17-25-27
    // cout << "\nTransversal in order\n";
    // pohon.inOrder(root);
    // // 12-15-17-20-25-27
    // cout << "\nTransversal post order\n";
    // pohon.postOrder(root);
   
    Node *root = NULL;
    Tree T;
    root = NULL;
    root = T.insertBinaryRoot(root,15);
    root = T.insertBinaryRoot(root,26); 
    root = T.insertBinaryRoot(root,8); 
    root = T.insertBinaryRoot(root,12);
    root = T.insertBinaryRoot(root,20); 
    root = T.insertBinaryRoot(root,6);
    root = T.insertBinaryRoot(root,9);
    root = T.insertBinaryRoot(root,14);
    root = T.insertBinaryRoot(root,35);
    cout << "Transversal preOrder " << endl;
    T.preOrder(root);

    cout << "\nPre Order: " << endl; 
    T.preOrder(root);
    cout << "\nIn Order: " << endl; 
    T.inOrder(root);
    cout << "\nPost Order: " << endl; 
    T.postOrder(root);
    
    int Tinggi;
    Tinggi = T.heightNode(root);
    cout << "\nTinggi Tree (mulai dari 1) : " << Tinggi << endl;
    cout << "Transversal Level Order : " << endl;
    T.levelOrder(root);

    NodeAritmatika *akar = new NodeAritmatika('*');
    akar->left = new NodeAritmatika('4');
    akar->right = new NodeAritmatika('/');
    akar->right->left = new NodeAritmatika('6');
    akar->right->right = new NodeAritmatika('2');
    Tree witArit;
    cout << "Cetak : "; // (4*(6/2))
    witArit.inOrderAritmatika(akar);
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

Node *Tree::insertBinaryRoot(Node *root, int data){
    if(root == NULL){
        root = new Node(data);
    }else if(data < root->data){
        root->left = insertBinaryRoot(root->left, data);
    } else {
        root->right = insertBinaryRoot(root->right, data);
    }
    return root;
}

void Tree::levelOrder(Node *root) {
    int h = heightNode(root);
    for(int i=0;i<h;i++){
        PrintCurrentLevel(root, i);
    }
}

int Tree::heightNode(Node *root) {
    if(root == NULL){
        return 0;
    }else {
        int leftH = heightNode(root->left);
        int rightH = heightNode(root->right);

        return 1+max(leftH, rightH);
    }
}

void Tree::PrintCurrentLevel(Node *root, int level){
    if(root != NULL){
        if(level == 0){
            cout << root->data << " ";
        }else if(level > 0){
            PrintCurrentLevel(root->left,level-1);
            PrintCurrentLevel(root->right,level-1);
        }
    }
}

void Tree::inOrderAritmatika(NodeAritmatika *root){
    if(root != NULL){
        if(root->left != NULL && root->right != NULL)
        cout << "(";
        inOrderAritmatika(root->left);
        cout << root->data << " ";
        inOrderAritmatika(root->right);
        if(root->left != NULL && root->right != NULL)
        cout << ")";
    }
}

