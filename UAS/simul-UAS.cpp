#include <iostream>

using namespace std;

class NodeKendaraan {
    public:
    string data = "";
    NodeKendaraan *left = nullptr;
    NodeKendaraan *right = nullptr;

    NodeKendaraan() {
    }

    NodeKendaraan (string data) {
        this->data = data;
    }
};

class Tree {
    public:
    NodeKendaraan *root;

    void printTree(NodeKendaraan *root, string indent="", bool last = true);
    int hitungNode(NodeKendaraan *root);
    bool cari(NodeKendaraan *root, string key);
    string cari2(NodeKendaraan *root,  string key);
};

int main() {

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

    cout << "=== cari 2 ===" << endl; 
    cout << "Apakah ada node Matic " << k.cari2(k.root, "Matic") << endl;
    cout << "Apakah ada node Pajero " << k.cari2(k.root, "Pajero") << endl;


    return 0;
}

int Tree::hitungNode(NodeKendaraan *root)
{
    if (root == nullptr) return 0;

    return 1 + hitungNode(root->left) + hitungNode(root->right);
}

void Tree::printTree(NodeKendaraan *root, string indent, bool last) 
{
    if (root == nullptr) return;

    cout << indent;

    if (last) {
        cout << "R----";
        indent += "    ";
    } else {
        cout << "L----";
        indent += "|    ";
    }

    cout << root->data << endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
}

bool Tree::cari(NodeKendaraan *root, string key) 
{
    if (root == nullptr) return false;

    if (root->data == key) return true;

    if (cari(root->left, key)) return true;

    if (cari(root->right, key)) return true;

    return false;
}

string Tree::cari2(NodeKendaraan *root, string key) 
{
    if (root == nullptr) return "Tidak ada";

    if (root->data == key 
        || cari(root->left, key) 
        || cari(root->right, key)) return "Ada";

    return "Tidak ada";
}