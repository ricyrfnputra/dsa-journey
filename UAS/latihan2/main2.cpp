#include<iostream>
using namespace std;

class NodeMakanan{
    public:
    string data = "";

    NodeMakanan *left = NULL;
    NodeMakanan *right = NULL;

    NodeMakanan(string data){
        this->data = data;
    }
};

class Tree{
    public:
    NodeMakanan *root;

    void printTree(NodeMakanan *root, string indent ="", bool last = true);
    int hitungNode(NodeMakanan *root);
    bool cariNode(NodeMakanan *root, string key);
    
};

int main(){

    Tree M;

    M.root = new NodeMakanan("Makanan");
    M.root->left = new NodeMakanan("Pokok");
    M.root->left->left = new NodeMakanan("Nasi");
    M.root->left->left->left = new NodeMakanan("Putih");
    M.root->left->left->right = new NodeMakanan("Merah");
    M.root->left->right = new NodeMakanan("Roti");
    M.root->left->right->left = new NodeMakanan("Tawar");
    M.root->left->right->right = new NodeMakanan("Gandum");
    M.root->right = new NodeMakanan("Camilan");
    M.root->right->left = new NodeMakanan("Kue");
    M.root->right->left->left = new NodeMakanan("Basah");
    M.root->right->left->right = new NodeMakanan("Kering");
    M.root->right->right = new NodeMakanan("keripik");
    M.root->right->right->left = new NodeMakanan("singkong");
    M.root->right->right->right = new NodeMakanan("kentang");

    M.printTree(M.root);

    cout << "Jumlah node ada " << M.hitungNode(M.root) << " Node" << endl;
    cout << "Apakah ada node Pokok" << (M.cariNode(M.root, "Pokok") ? "ada" : "tidak ada")<< endl;
}

bool Tree::cariNode(NodeMakanan *root, string key){
    if(root == NULL) return false;
    if(root->data == key) return true;

    return cariNode(root->left,key) || cariNode(root->right,key);

}

int  Tree::hitungNode(NodeMakanan *root){
    if(root == NULL ) return 0;
    return 1+ hitungNode(root->left) + hitungNode(root->right);
}

void Tree::printTree(NodeMakanan *root, string indent, bool last){
    if(root == NULL) return;

    cout << indent;

    if(last){
        cout << "R----";
        indent += "     ";
    } else {
        cout << "L-----";
        indent += "|     ";
    }

    cout << root->data << endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
}



// LATIHAN (JADI TIDAK MASUK KE MAIN COE)
/*cout << "Jumlah node ada " << M.hitungNode(M.root) << " Node" << endl;


int Tree::hitunngNode(NodeMakanan *root){

    if(root == NULL) return 0;
    return 1+ hitungNode(root->left) + hitungNode(root->right);
}

cout << "Apakah ada node Pisang" << (M.cariNode(M.root, "Pisang")? "ada" : "tidak ada");

bool Tree::cariNode(NodeMakanan *root, string key){
    if(root == NULL) return false;
    if(root->data == key) retrun true;
    return cariNode(root->left,key) || cariNode(root->right,key);
}
*/


