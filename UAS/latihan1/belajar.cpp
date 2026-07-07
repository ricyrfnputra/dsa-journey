#include<iostream>
using namespace std;

class NodeKendaraan{
    public:
    string jenis =  " ";
    NodeKendaraan *left = NULL;
    NodeKendaraan *right = NULL;

    NodeKendaraaan(string jenis){
        this->jenis = jenis;
    }
};

class Tree{
    public:
    NodeKendaraan *root;
    void printTree(NodeKendaraan *root, string indent, bool last = true);
    int hitungNode(NodeKendaraan *root);
    bool cari(NodeKendaraan *root, string target);
    string cari2(NodeKendaraan *root, string target);
}


int main()
{
    
    Tree k;
    k.root = new NodeKendaraan("Kendaraan");
    k.root->left = new NodeKendaraan("Transportasi");
    k.root->left->left = new NodeKendaraan("Motor");
    k.root->left->left->left = new NodeKendaraan("Bebek");
    k.root->left->left->right = new NodeKendaraan("Sport");
    k.root->left->right = new NodeKendaraan("Mobil");
    k.root->left->right->left = new NodeKendaraan("Matic");
    k.root->left->right->right = new NodeKendaraan("Manual");
    k.root->right = new NodeKendaraan("Logistik");
    k.root->right->left = new NodeKendaraan("Truk");
    k.root->right->right = new NodeKendaraan("Pickup");

    k.printTree(k.root);

    cout << "Pada pohon kendaraaan ada " << k.hitungNode(k.root) << " node." << endl;
    cout << "Apakah ada node Sport " << (k.cari(k.root, "Sport") ? "Ada" : "Tidak ada") << endl;
    cout << "Apakah ada node Pajero " << (k.cari(k.root, "Pajero") ? "Ada" : "Tidak ada") << endl;

    // cout << "=== cari 2 ===" << endl; 
    // cout << "Apakah ada node Matic " << k.cari2(k.root, "Matic") << endl;
    // cout << "Apakah ada node Pajero " << k.cari2(k.root, "Pajero") << endl;


    return 0; 
}   

void Tree::printTree(NodeKendaraan *root, string indent, bool last){
    if(root != NULL){
        cout << indent;
        if(last){
            cout << "R----";
            indent += "     ";
        }
        else{
            cout << "L-----";
            indent += "|     ";
        }
        cout << root->jenis << endl;

        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}

int Tree::hitungNode(NodeKendaraan *root){
    if(root == NULL)
        return 0;

        return 1+ hitungNode(root->left) + hitungNode(root->right);
}

string Tree::cari(NodeKendaraan *root, string indent){
    string hasil = "Tidak ada";

    if(root->jenis == target){
        if(root->jenis == target){
            hasil = "Ada";
        }else{
            hasil = cari(root->left, target);

            if(hasil == "Tidak ada"){
                hasil = cari(root->right, target);
            }
        }
    }
    return hasil;
}



