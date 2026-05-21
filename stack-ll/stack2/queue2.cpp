#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string nama;
    Node *next;

    Node() { 
        nama = "";
        next = NULL;
    }

    Node(string nama) { 
        this->nama = nama;
        this->next = NULL;
    }
};


class Queue {
private:
    Node *head; 
    Node *tail; 
    int kapasitas;

public:
    Queue() { 
        head = NULL;
        tail = NULL;
        kapasitas = 100;
    }

    Queue(int kapasitas) { 
        head = NULL;
        tail = NULL;
        this->kapasitas = kapasitas;
    }

    bool isEmpty() {
        return head == NULL;
    }

    bool isFull() {
        return panjangQ() >= kapasitas;
    }

    int panjangQ() {
        int count = 0;
        Node *temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    
    void enqueue(string nama) {
        if (isFull()) {
            cout << "Maaf, kapasitas penuh" << endl;
            return;
        }
        Node *newNode = new Node(nama);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    
    void enqueuePriority(string nama) {
        if (isFull()) {
            cout << "Maaf, kapasitas penuh" << endl;
            return;
        }
        Node *newNode = new Node(nama);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Hapus depan
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong!" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head == NULL) tail = NULL;
        delete temp;
    }

    // Hapus belakang
    void dequeueBelakang() {
        if (isEmpty()) {
            cout << "Queue kosong!" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    // Lihat elemen terdepan
    string peek() {
        if (isEmpty()) return "";
        return head->nama;
    }

    // Cetak semua isi queue
    void cetak() {
        if (isEmpty()) {
            cout << "Queue kosong!" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL) {
            cout << "[" << temp->nama << " | " << temp->next << "]";
            if (temp->next != NULL) cout << " --> ";
            temp = temp->next;
        }
        cout << endl;
    }
};


// queue
int main() {
    cout << "Queue dengan class" << endl;

    Queue hokage(3);

    hokage.enqueue("Sasuke");
    hokage.enqueue("Sakura");
    hokage.cetak();

    hokage.enqueuePriority("Naruto");
    hokage.cetak();
    cout << "Calon Hokage urutan pertama adalah " << hokage.peek() << endl;

    hokage.enqueue("Boruto");
    hokage.enqueuePriority("Kakashi");
    hokage.cetak();
    cout << "Calon Hokage urutan pertama adalah " << hokage.peek() << endl;

    return 0;
}