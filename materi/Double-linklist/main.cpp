// NIM  : A11.2025.16464
// NAME : RICY RIFANI PUTRA
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next = NULL;
    Node* prev = NULL;

    Node () {
        data = 0;
    }
    Node (int data){
        this->data = data;
    }
};

class DoubleLinkedList {
    int jumlah = 0; //jika insert jumlah++, hapus maka jumlah--
    
    public:
    Node* head;
    Node* tail;

    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
        jumlah = 0;
    }

    void insertDepan(int value);
    void insertBelakang(int value);
    void cetak();
    void hapusDepan();
    void hapusBelakang();
    int hitungNode();     
    bool searchData(int k); 
    bool searchData2(int k); 
    void insertMid(int value, int n); 
    void hapusMid(int value); 
    void insertAfter(int value, int AValue);
    void insertBefore(int value, int BValue);
    void prioritas(int posisi, int n);
    void tukarHead(int posisi, int n);
    void hapusDuplikat();
};

int main () {

    DoubleLinkedList dll;
    
    dll.insertDepan(100);       
    dll.insertBelakang(84);     
    dll.insertBelakang(5);      
    dll.insertBelakang(50);      
    dll.insertBelakang(25);

    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";
    cout << "\nsetelah hapus depan\n";
    dll.hapusDepan();
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";   
    cout << "\nsetelah hapus belakang\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " << endl;  
    dll.hapusBelakang(); 
    cout << "\njumlah node: " << dll.hitungNode() << endl;
    cout << "apakah ada angka 84? " << dll.searchData(84) << endl;
    cout << "apakah ada angka 5? " << dll.searchData(5) << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";  
    cout << "\nsetelah insert mid (0)\n";
    dll.insertMid(0, dll.hitungNode());
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";  
    cout << "\nsetelah insert mid (1)\n";         
    dll.insertMid(1 , dll.hitungNode());     
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";  
    cout << "\nsetelah hapus mid\n";
    dll.hapusMid(1);        
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";   //insert after insert before
    cout << "\nsetelah insert after\n";
    dll.insertAfter(50, 84);
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";  
    cout << "\nsetelah insert before\n";
    dll.insertBefore(25, 84);
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";
    cout << "\nsetelah prioritas\n";
    dll.prioritas(3, dll.hitungNode());
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";
    cout << "\nsetelah tukar head\n";
    dll.tukarHead(2, dll.hitungNode());
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";
    cout << "\nhapus duplikat\n";
    dll.hapusDuplikat();

    return 0;
}

void DoubleLinkedList::tukarHead(int posisi, int n){
    if(posisi>1 && posisi<n){
    Node *current = head;
    Node *previous = head;

    // cari node di posisi
    for(int i = 1; i < posisi; i++){
        previous = current;
        current = current->next;
    }
    if(current != NULL){
        // lepas node dari posisi lama
        previous->next = current->next;
        // pindah ke depan (head)
        current->next = head;
        head = current;
        current->prev = NULL;
        }
    }
    cetak();
}


void DoubleLinkedList::insertBefore(int value, int BValue){
    Node *temp = new Node(value);
    Node *current = head;
    while(current != NULL && current->data != BValue){
        current = current->next;
    }
    if(current == NULL) return;

    Node *prevNode = current->prev;

    temp->next = current;
    temp->prev = prevNode;
    current->prev = temp;

    if(prevNode != NULL){
        prevNode->next = temp;
    } else {
        head = temp;
    }

    jumlah++;
    cetak();
}

void DoubleLinkedList::insertAfter(int value, int AValue){
    Node *temp = new Node(value);
    Node *current = head;
    while(current != NULL && current->data != AValue){
        current = current->next;
    }
    if(current == NULL) return;

    Node *nextNode = current->next;

    temp->prev = current;
    temp->next = nextNode;
    current->next = temp;

    if(nextNode != NULL){
        nextNode->prev = temp;
    } else {
        tail = temp;
    }

    jumlah++;
    cetak();
}

void DoubleLinkedList::hapusDepan() {
    if (head != NULL) {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        jumlah--;
        cetak();
    }
}

void DoubleLinkedList::hapusBelakang() {
    if (tail != NULL) {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        jumlah--;
        cetak();
    }
}

int DoubleLinkedList::hitungNode() {
    return jumlah;
}

bool DoubleLinkedList::searchData(int k) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == k) return true;
        temp = temp->next;
    }
    return false;
}

bool DoubleLinkedList::searchData2(int k) {
    for (Node *temp = head; temp != NULL; temp = temp->next) {
        if (temp->data == k) return true;
    }
    return false;
}

void DoubleLinkedList::insertMid(int value, int n) {

    Node *temp = new Node(value);
    int mid = (n/2) - 1;
    Node *current = head;
    for (int i = 0; i < mid; i++) {
        current = current->next;
    }
    Node *nextNode = current->next;

    temp->prev = current;
    temp->next = nextNode;
    current->next = temp;

    if (nextNode != NULL) {
        nextNode->prev = temp;
    }else {
        tail = temp;
    }
    jumlah++;
    cetak();
}

void DoubleLinkedList::hapusMid(int value) {
    if (head == NULL) return;

    Node *current = head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }
    if (current == NULL) return;

    if (current == head) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
    } else if (current == tail) {
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL;
        }
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
    jumlah--;
    cetak();
}

void DoubleLinkedList::prioritas(int posisi, int n){
    if(posisi>1 && posisi<n){
        Node *current = head;
        Node *previous = head;

        // cari node di posisi
        for(int i = 1; i < posisi; i++){
            previous = current;
            current = current->next;
        }
        if(current != NULL){
            // lepas node dari posisi lama
            previous->next = current->next;
            // pindah ke depan (head)
            current->next = head;
            head = current;
            current->prev = NULL;
        }
    }
    cetak();
}

void DoubleLinkedList::hapusDuplikat(){
    Node *current = head;

    while(current != NULL){
        Node *temp = current;
        while(temp->next != NULL){
            if(temp->next->data == current->data){
                Node *hapus = temp->next;
                temp->next = temp->next->next;
                delete hapus;
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
    }
    cetak();
}

void DoubleLinkedList::insertDepan(int value) {
    Node *temp = new Node(value);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head ->prev = temp;
        head = temp;
    }
    jumlah++;
    cetak();
}

void DoubleLinkedList::insertBelakang(int value){
    Node *temp = new Node(value);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    jumlah++;   
    cetak();
}

void DoubleLinkedList::cetak() {
    Node *temp = head;
    
    while (temp != NULL) {
        cout << "[ " << temp->prev << "|" << temp->data << "|" << temp->next << " ] ";
        temp = temp->next;
        if (temp != NULL) cout << " <--- ---> ";
    }
    cout << endl;
}

