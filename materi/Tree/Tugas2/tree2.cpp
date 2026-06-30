#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node*left;
    Node*right;

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
    char data =' ';
    NodeAritmatika*left = NULL;
    NodeAritmatika*right = NULL;

    NodeAritmatika(char data){
        this->data = data;

    }
};

class Tree{
    public:
    Node *root;

    Node *insertBinaryRoot(Node *root, int nilai);
    void PreOrder(Node *root);
    void inOrder(Node *root);
    void postOrder(Node *root);
    void printCurrentLevel(Node *root, int level);
    void levelOrder(Node  *root);
    int heightNode(Node *root);
    int heightNodeAritmatika(NodeAritmatika *root);
    void inOrderArtimatika(NodeAritmatika *root);
    bool PerfectBinaryArit(NodeAritmatika *root, int tinggi, int level);
    void printTree(Node *root, string indent = "", bool last = true);
    void printTreeArit(NodeAritmatika *root, string indent = "", bool last = true);
};


int main(){
    // Insert Manual Pohon Kecil
    cout << "=== Pohon Kecil Insert Manual ===\n";
    Tree pohon;
    Node *root = new Node(20);
    root->left = new Node(5);
    root->right = new Node(25);
    cout << "Pre Order: " << endl; pohon.PreOrder(root);
    cout << "\nIn Order: " << endl; pohon.inOrder(root);
    cout << "\nPost Order: " << endl; pohon.postOrder(root);
    cout << "\nTinggi tree mulai dari 1 : " << pohon.heightNode(root);
    cout << "\nLevel Order : "; pohon.levelOrder(root);
    cout << endl;
    cout << "===Print Tree===\n";
    pohon.printTree(root);

    // Insert Binary Pohon Besar
    cout << "\n\n=== Pohon Besar Insert Binary ===\n";
    Tree POHON;
    Node *root2 = NULL;
    root2 = POHON.insertBinaryRoot(root2, 20);
    root2 = POHON.insertBinaryRoot(root2, 11); root2 = POHON.insertBinaryRoot(root2, 23);
    root2 = POHON.insertBinaryRoot(root2, 8); root2 = POHON.insertBinaryRoot(root2, 22);
    root2 = POHON.insertBinaryRoot(root2, 19); root2 = POHON.insertBinaryRoot(root2, 30);
    cout<< "Pre Order: " << endl; POHON.PreOrder(root2);
    cout<< "\nIn Order: " << endl; POHON.inOrder(root2);
    cout<< "\nPost Order: " << endl; POHON.postOrder(root2);
    cout << "\nTinggi tree mulai dari 1 : " << POHON.heightNode(root2);
    cout << "\nLevel Order : "; POHON.levelOrder(root2);
    cout << endl;
    cout << "===Print Tree===\n";
    POHON.printTree(root2);

    // Pohon Aritmatika Kecil Tidak Seimbang
    cout << "\n\n=== Pohon Aritmatika Kecil Tidak Seimbang ===\n";
    Tree witArit;
    NodeAritmatika *root3 = new NodeAritmatika('*');
    root3->left = new NodeAritmatika('4');
    root3->right = new NodeAritmatika('/');
    root3->right->left = new NodeAritmatika('6');
    root3->right->right = new NodeAritmatika('2');
    cout << "Height Node : " << witArit.heightNodeAritmatika(root3);
    cout << "\nCetak InOrder : "; witArit.inOrderArtimatika(root3);x
    cout << "\nApakah Perfect Binary? Jawaban : " << witArit.PerfectBinaryArit(root3, witArit.heightNodeAritmatika(root3), 0);
    cout << endl;
    cout << "=== Print Tree ===\n";
    witArit.printTreeArit(root3);

    // Pohon Aritmatika Besar Seimbang
    cout << "\n\n=== Pohon Aritmatika Besar Seimbang ===\n";
    Tree witArit2;
    NodeAritmatika *root4 = new NodeAritmatika('*');
    root4->left = new NodeAritmatika('+');
    root4->right = new NodeAritmatika('/');
    root4->left->left = new NodeAritmatika('6');
    root4->left->right = new NodeAritmatika('2');
    root4->right->left = new NodeAritmatika('6');
    root4->right->right = new NodeAritmatika('2');
    cout << "Height Node : " << witArit2.heightNodeAritmatika(root4);
    cout << "\nCetak InOrder : "; witArit2.inOrderArtimatika(root4);
    cout << "\nApakah Perfect Binary? Jawaban : " << witArit2.PerfectBinaryArit(root4, witArit.heightNodeAritmatika(root4), 0);
    cout << endl;
    cout << "=== Print Tree ===\n";
    witArit2.printTreeArit(root4);

    return 0;
}

void Tree::PreOrder(Node*root){
    if(root !=NULL){
        cout << root->data <<" ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void Tree::inOrder(Node*root){
    if(root !=NULL){
        inOrder(root->left);
        cout << root->data <<" ";
        inOrder(root->right);
    }
}

void Tree::postOrder(Node*root){
    if(root  != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data <<" ";
    }
}

Node *Tree::insertBinaryRoot(Node *root, int nilai){
    if(root == NULL){
        root = new Node(nilai);
    }
    else if(nilai <= root->data){
        root->left = insertBinaryRoot(root->left, nilai);
    }
    else{
        root->right = insertBinaryRoot(root->right, nilai);
    }
    return root;
}

void Tree::printCurrentLevel(Node*root, int level){
    if(root != NULL){
        if(level == 0){
            cout << root->data << " ";
        }else if(level > 0){
            printCurrentLevel(root->left, level-1);
            printCurrentLevel(root->right, level-1);
        }
    }
}
void Tree::levelOrder(Node*root){
    int h = heightNode(root);
    for(int i=0; i<h; i++){
        printCurrentLevel(root,i);
    }
}

int Tree::heightNode(Node*root){
    if(root == NULL){
        return 0;
    }else{
        int leftH=heightNode(root->left);
        int rightH=heightNode(root->right);

    return 1 + max(leftH, rightH);
    }
}

int Tree::heightNodeAritmatika(NodeAritmatika *root){
    if(root == NULL){
        return 0;
    }else{
        int leftH=heightNodeAritmatika(root->left);
        int rightH=heightNodeAritmatika(root->right);

    return 1 + max(leftH, rightH);
    }
}

void Tree::inOrderArtimatika(NodeAritmatika*root){
    if(root !=NULL){
        if(root->left !=NULL && root->right !=NULL)
            cout <<"(";
        inOrderArtimatika(root->left);
        cout << root->data <<" ";
        inOrderArtimatika(root->right);
        if(root->left !=NULL && root->right !=NULL)
            cout << ")";
    }
}

bool Tree::PerfectBinaryArit(NodeAritmatika*root, int tinggi, int level){
    if(root == NULL){
        return true;
    }
    if(root->left == NULL && root->right == NULL){
        return tinggi == level +1;
    }
    if(root->left == NULL || root->right == NULL){
        return false;
    }
    return PerfectBinaryArit(root->left, tinggi, level +1)&&PerfectBinaryArit(root->right, tinggi, level +1);
}

void Tree::printTree(Node *root, string indent, bool last){
    if(root != NULL){
        cout << indent;
        if(last){
            cout << "R----";
            indent += "     ";
        }
        else{
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
        }
        else{
            cout << "L----";
            indent += "|     ";
        }
        cout << root->data << endl;
        printTreeArit(root->left, indent, false);
        printTreeArit(root->right, indent, true);
    }
}
