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

class NodeAritmatika{
    public:
    char data = ' ';
    NodeAritmatika *left = NULL;
    NodeAritmatika *right = NULL;
    NodeAritmatika(char data){
        this->data = data;
    }
};

class Tree{
    public:
    Node *root = NULL;
    NodeAritmatika *rootArit = NULL;   // root khusus untuk pohon aritmatika

    Node *insertBinaryRoot(Node *root, int nilai);
    void preOrder(Node *root);
    void inOrder(Node *root);
    void postOrder(Node *root);
    int heightNode(Node *root);
    void levelOrder(Node *root);
    void PrintCurrentLevel(Node *root, int level);
    void inOrderAritmatika(NodeAritmatika *root);
    bool isPerfectBinaryArit(NodeAritmatika *root, int tinggi, int level);

    //
    void printTree(Node *root, string indent ="", bool last=true);
    int heightNodeAritmatika(NodeAritmatika *root);
    void printTreeArit(NodeAritmatika *root, string indent = "", bool last = true);
};

int main()
{
    Tree pohon;

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

    // Tidak Seimbang
    NodeAritmatika *akar = new NodeAritmatika('*');
    akar->left = new NodeAritmatika('4');
    akar->right = new NodeAritmatika('/');
    akar->right->left = new NodeAritmatika('6');
    akar->right->right = new NodeAritmatika('2');
    Tree witArit;

    cout << endl;
    cout << "Tree yang tidak seimbang" << endl;
    cout << "Cetak : "; // (4*(6/2))
    witArit.inOrderAritmatika(akar);

    // Seimbang
    NodeAritmatika *akar2 = new NodeAritmatika('+');
    akar2->left = new NodeAritmatika('*');
    akar2->left->left = new NodeAritmatika('9');
    akar2->left->right = new NodeAritmatika('6');
    akar2->right = new NodeAritmatika('-');
    akar2->right->left = new NodeAritmatika('8');
    akar2->right->right = new NodeAritmatika('5');
    cout << endl;
    cout << "Tree yang seimbang" << endl;

    cout << "Cetak : "; // ((9*6)+(8-5))
    witArit.inOrderAritmatika(akar2);
    cout << endl;

    // TREE 1 (angka)
    Tree t;
    t.root = new Node(20);
    t.root->left = new Node(15);
    t.root->right = new Node(25);
    t.root->left->left = new Node(12);
    t.root->left->right = new Node(17);
    t.root->right->right = new Node(27);
    cout << "\n==============\n";
    t.printTree(t.root);
 
    Tree tA;
    tA.rootArit = new NodeAritmatika('+');
    tA.rootArit->left = new NodeAritmatika('*');
    tA.rootArit->right = new NodeAritmatika('9');
    tA.rootArit->left->left = new NodeAritmatika('6');
    tA.rootArit->left->right = new NodeAritmatika('-');
    tA.rootArit->left->right->left = new NodeAritmatika('8');
    tA.rootArit->left->right->right = new NodeAritmatika('2');
    cout << "\n==============\n";
    tA.printTreeArit(tA.rootArit);

    return 0;
}

// Cetak pohon angka (Node)
void Tree::printTree(Node *root, string indent, bool last){
    if(root != NULL){
        cout << indent;
        if(last){
            cout << "R----";
            indent += "     ";
        }
        else{
            cout << "L----";
            indent += "     ";
        }
        cout << root->data << endl;

        printTree(root->left, indent, false);

        
        printTree(root->right, indent, true);
    }
}

// Cetak pohon aritmatika (NodeAritmatika) -- method milik class Tree
void Tree::printTreeArit(NodeAritmatika *root, string indent, bool last){
    if(root != NULL){
        cout << indent;
        if(last){
            cout << "R----";
            indent += "     ";
        }
        else{
            cout << "L----";
            indent += "     ";
        }
        cout << root->data << endl;

        printTreeArit(root->left, indent, false);
        printTreeArit(root->right, indent, true);
    }
}

bool Tree::isPerfectBinaryArit(NodeAritmatika *root, int tinggi, int level){
    if(root == NULL)
        return true;

    if(root->left == NULL && root->right == NULL)
        return tinggi == level + 1;

    if(root->left == NULL || root->right == NULL)
        return false;

    return isPerfectBinaryArit(root->left, tinggi, level + 1) &&
           isPerfectBinaryArit(root->right, tinggi, level + 1);
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

int Tree::heightNode(Node *root) {
    if(root == NULL){
        return 0;
    }else {
        int leftH = heightNode(root->left);
        int rightH = heightNode(root->right);

        return 1+max(leftH, rightH);
    }
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
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void Tree::postOrder(Node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
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