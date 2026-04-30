/*
    Name    : Ricy Rifani Putra
    Nim     : A11.2025.16464
    Matery  : Single LinkedList
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // INSERT DEPAN
    void insertDepan(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;       // ← hapus "sni" di sini
    }

    // CETAK LIST
    void cetak() {
        Node* temp = head;
        while (temp) {
            string nextVal = temp->next ? to_string(temp->next->data) : "NULL";
            cout << "[" << temp->data << "|" << nextVal << "] --> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // HITUNG NODE
    int hitungNode() {
        int s = 0;
        Node* temp = head;
        while (temp) {
            s++;
            temp = temp->next;
        }
        return s;
    }

    // HAPUS TENGAH
    void hapusMid(int n) {
        if (!head || n < 2) return;

        int mid = n / 2;
        Node* temp = head;
        Node* previous = NULL;

        for (int i = 0; i < mid; i++) {
            previous = temp;
            temp     = temp->next;
        }

        previous->next = temp->next;
        delete temp;
    }

    // INSERT AFTER
    void insertAfter(int nodeVal, int value) {
        Node* temp = head;
        while (temp && temp->data != nodeVal)
            temp = temp->next;

        if (temp) {
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // INSERT BEFORE
    void insertBefore(int nodeVal, int value) {
        if (!head) return;

        if (head->data == nodeVal) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        Node* previous = NULL;

        while (temp && temp->data != nodeVal) {
            previous = temp;
            temp = temp->next;
        }

        if (temp) {
            Node* newNode = new Node(value);
            newNode->next = temp;
            previous->next = newNode;
        }
    }
};

int main() {
    LinkedList sll;

    sll.insertDepan(14);
    sll.insertDepan(1);
    sll.insertDepan(84);
    sll.insertDepan(100);

    cout << "Linked list awal:\n";
    sll.cetak();

    cout << "\nsll.hapusMid-1\n";
    sll.hapusMid(sll.hitungNode());
    sll.cetak();

    cout << "\nsll.hapusMid-2\n";
    sll.hapusMid(sll.hitungNode());
    sll.cetak();

    cout << "\nsll.insertAfter(100, 17)\n";
    sll.insertAfter(100, 17);
    sll.cetak();

    cout << "\nsll.insertAfter(14, 17)\n";
    sll.insertAfter(14, 17);
    sll.cetak();

    cout << "\nsll.insertBefore(14, 42)\n";
    sll.insertBefore(14, 42);
    sll.cetak();

    cout << "\nsll.insertBefore(100, 42)\n";
    sll.insertBefore(100, 42);
    sll.cetak();

    return 0;
}