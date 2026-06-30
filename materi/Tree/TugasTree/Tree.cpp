// Name     : Ricy Rifani Putra
// Nim      : A11.2025.16464
// Matery   : Tree
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(){
        data = 0;
        left = right = NULL;
    }
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

class NodeAritmatika{
    public:
    char data = ' ';     
    NodeAritmatika *right = NULL;

    NodeAritmatika(char data){
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
    void printCurrentLevel(Node *root, int level);
    void levelOrder(Node *root);
    int heightNode(Node *root);
    int heightNodeAritmatika(NodeAritmatika *root);
    void inOrderAritmatika(NodeAritmatika *root);
    bool isPerfectBinaryArit(NodeAritmatika *root, int tinggi, int level);
    void printTree(Node *root, string indent = "", bool last = true);
    void printTreeArit(NodeAritmatika *root, string indent = "", bool last = true);
};


int main()
{
    // =========================================================
    // 1. Pohon angka kecil - Insert Manual
    cout << "=========================================================\n";
    cout << "---- 1. Pohon Kecil Insert Manual ----\n";
    Node *root = new Node(20);
    root->left = new Node(15);
    root->left->right = new Node(17);
    root->left->left = new Node(12);
    root->right = new Node(25);
    root->right->right = new Node(27);
    Tree pohon;
    
    cout << "pre order\n";
    pohon.preOrder(root);
    // 20-15-12-17-25-27
    cout << "\n in order\n";
    pohon.inOrder(root);
    // 12-15-17-20-25-27
    cout << "\n post order\n";
    pohon.postOrder(root);
    cout << "\nLevel Order\n";
    pohon.levelOrder(root);

    cout << endl;
    cout << "Print Tree :\n";
    pohon.printTree(root);

    // 2. Pohon angka besar - Insert Binary
    cout << "\n\n---- 2. Pohon Besar Insert Binary ----\n";
    Node *root1 = NULL;
    Tree T;
    root1 = T.insertBinaryRoot(root1, 15);
    root1 = T.insertBinaryRoot(root1, 26);
    root1 = T.insertBinaryRoot(root1, 8);
    root1 = T.insertBinaryRoot(root1, 12);
    root1 = T.insertBinaryRoot(root1, 20);
    root1 = T.insertBinaryRoot(root1, 6);
    root1 = T.insertBinaryRoot(root1, 9);
    root1 = T.insertBinaryRoot(root1, 14);
    root1 = T.insertBinaryRoot(root1, 35);

    cout << "Pre Order: " << endl;
    T.preOrder(root1);
    cout << "\nIn Order: " << endl;
    T.inOrder(root1);
    cout << "\nPost Order: " << endl;
    T.postOrder(root1);

    int tinggi;
    tinggi = T.heightNode(root1);
    cout << "\nTinggi Tree (mulai dari 1) : " << tinggi << endl;
    cout << "Level Order : ";
    T.levelOrder(root1);
    cout << endl;
    cout << "Print Tree :\n";
    T.printTree(root1);

    // 3. Pohon Aritmatika kecil - Tidak Seimbang
    cout << "\n\n---- 3. Pohon Aritmatika Kecil Tidak Seimbang ----\n";
    NodeAritmatika *akar = new NodeAritmatika('*');
    akar->left = new NodeAritmatika('4');
    akar->right = new NodeAritmatika('/');
    akar->right->left = new NodeAritmatika('6');
    akar->right->right = new NodeAritmatika('2');
    Tree witArit;

    cout << "Height Node : " << witArit.heightNodeAritmatika(akar);
    cout << "\nCetak : "; // (4*(6/2))
    witArit.inOrderAritmatika(akar);
    cout << endl;
    cout << "Apakah Perfect Binary? Jawaban : " << witArit.isPerfectBinaryArit(akar, witArit.heightNodeAritmatika(akar), 0) << endl;
    cout << "Print Tree :\n";
    witArit.printTreeArit(akar);

    // 4. Pohon Aritmatika besar - Seimbang
    cout << "\n\n---- 4. Pohon Aritmatika Besar Seimbang ----\n";
    NodeAritmatika *akar2 = new NodeAritmatika('+');
    akar2->left = new NodeAritmatika('*');
    akar2->left->left = new NodeAritmatika('9');
    akar2->left->right = new NodeAritmatika('6');
    akar2->right = new NodeAritmatika('-');
    akar2->right->left = new NodeAritmatika('8');
    akar2->right->right = new NodeAritmatika('5');
    Tree witArit2;

    cout << "Height Node : " << witArit2.heightNodeAritmatika(akar2);
    cout << "\nCetak : "; // ((9*6)+(8-5))
    witArit2.inOrderAritmatika(akar2);
    cout << endl;
    cout << "Apakah Perfect Binary? Jawaban : " << witArit2.isPerfectBinaryArit(akar2, witArit2.heightNodeAritmatika(akar2), 0) << endl;
    cout << "Print Tree :\n";
    witArit2.printTreeArit(akar2);

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

Node *Tree::insertBinaryRoot(Node *root, int nilai){
    if(root == NULL){
        root = new Node(nilai);
    } else if(nilai < root->data){
        root->left = insertBinaryRoot(root->left, nilai);
    } else {
        root->right = insertBinaryRoot(root->right, nilai);
    }
    return root;
}

void Tree::printCurrentLevel(Node *root, int level){
    if(root != NULL){
        if(level == 0){
            cout << root->data << " ";
        } else if(level > 0){
            printCurrentLevel(root->left, level - 1);
            printCurrentLevel(root->right, level - 1);
        }
    }
}

void Tree::levelOrder(Node *root){
    int h = heightNode(root);
    for(int i = 0; i < h; i++){
        printCurrentLevel(root, i);
    }
}

int Tree::heightNode(Node *root){
    if(root == NULL){
        return 0;
    } else {
        int leftH = heightNode(root->left);
        int rightH = heightNode(root->right);
        return 1 + max(leftH, rightH);
    }
}

int Tree::heightNodeAritmatika(NodeAritmatika *root){
    if(root == NULL){
        return 0;
    } else {
        int leftH = heightNodeAritmatika(root->left);
        int rightH = heightNodeAritmatika(root->right);
        return 1 + max(leftH, rightH);
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

void Tree::printTree(Node *root, string indent, bool last){
    if(root != NULL){
        cout << indent;
        if(last){
            cout << "R----";
            indent += "     ";
        } else {
            cout << "L----";
            indent += "|     ";
        }
        cout << root->data << endl;
        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}

void Tree::printTreeArit(NodeAritmatika *root, string indent, bool last){
    if(root != NULL){
        cout << indent;
        if(last){
            cout << "R----";
            indent += "     ";
        } else {
            cout << "L----";
            indent += "|     ";
        }
        cout << root->data << endl;
        printTreeArit(root->left, indent, false);
        printTreeArit(root->right, indent, true);
    }
}