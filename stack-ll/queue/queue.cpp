// Nama : Ricy Rifani Putra
// Nim  : A11.2025.16464

#include <iostream>
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

    bool isEmpty();
    void enqueue(string nama); 
    void dequeue();            
    void enqueuePriority(string nama); 
    string peek();
    int panjangQ();
    bool isFull();
    void cetak();
    void dequeueBelakang();      
};

bool Queue::isEmpty() {
    return head == NULL;
}

int Queue::panjangQ() {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

bool Queue::isFull() {
    return panjangQ() >= kapasitas;
}

void Queue::enqueue(string nama) {
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

void Queue::enqueuePriority(string nama) {
    if (isFull()) {
        dequeueBelakang(); 
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

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head == NULL) tail = NULL;
    delete temp;
}

void Queue::dequeueBelakang() {
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

string Queue::peek() {
    if (isEmpty()) return "";
    return head->nama;
}

void Queue::cetak() {
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