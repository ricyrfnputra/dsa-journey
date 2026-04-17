#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = nullptr;
    }
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node *head;
    Node *tail;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    void insertdepan(int value);
    void insertbelakang(int value);
    void cetak();
    void hapusDepan();
    void hapusBelakang();
    bool searchdata(int k);
    bool searchdata2(int k);
    int hitungNode();
};


int main() {
    cout << "single linked list manual" << endl;
    Node *head = new Node();
    head->data = 100;
    head->next = new Node();
    head->next->data = 84;
    head->next->next = new Node(5);

    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "single linked list class linked list" << endl;
    LinkedList sll;
    sll.insertdepan(2);
    sll.insertdepan(4);
    sll.insertbelakang(10);
    sll.cetak();

    return 0;
}


void LinkedList::hapusDepan(){
    if(head != nullptr){
        Node *temp = head;

        head = head->next;
        delete temp;
    }
}

void LinkedList::hapusBelakang(){
    if(head != nullptr){
        if(head == tail){
            Node *temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
        } else {
            Node *current = head;
            Node *previous = head;

            while(current->next != nullptr) {
                previous = current;
                current = current->next;
            }
            previous->next = nullptr;
            tail = previous;  
            delete current;
        }
    }
    cetak();
}

void LinkedList::insertdepan(int value) {
    Node *temp = new Node(value);
    if (head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void LinkedList::insertbelakang(int value) {
    Node *temp = new Node(value);
    if (head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    cetak();
}

int LinkedList::hitungNode(){
    int s = 0;
    Node *temp = head;
    
    while(temp != NULL){
        s++;
        temp = temp->next;
    }
    return s;
}


void LinkedList::cetak() {
    Node *temp = head;
    while (temp != nullptr) {
        cout << "["  << temp->data << " | " << temp->next << "]";
        if(temp->next != nullptr){
            cout << "->";   
        }
        temp = temp->next;
    }
    cout << endl;
}

