//19-5-2026
//materi kuliah stack
//menyalin ulang

#include <iostream>

using namespace std;

class Nodestack{
    public:
    string judul,penulis;
    Nodestack *next;

    Nodestack(){
        judul   = "";
        penulis = "";
        next    = NULL;
    }
    
    Nodestack(string judul,string penulis){
        this -> judul = judul;
        this -> penulis = penulis;
        next = NULL;
    }
};
class stack{
    private:
    Nodestack *top;

    public:
    stack(){
    top = NULL;
    }
    bool isEmpty();
    void push(string judul, string penulis);
    //tumpuk atau tambah
    void pop(); //ambil atau hapus
    void cetak();
};

class NodeQueue {
public:
    string judul, penulis;
    NodeQueue *next;

    NodeQueue() {
        judul = ""; penulis = ""; next = NULL;
    }
    NodeQueue(string judul, string penulis) {
        this->judul   = judul;
        this->penulis = penulis;
        next = NULL;
    }
};

class Queue {
private:
    NodeQueue *front, *rear;
public:
    Queue() { front = NULL; rear = NULL; }
    bool isEmpty();
    void enqueue(string judul, string penulis); // tambah ke belakang
    void dequeue();                              // hapus dari depan
    void cetak();
};

int main(){

    cout << " stack / tumpukan buku\n";
    stack s;

    s.push ("sporsi mie ayam sblum mati", "brian");
    s.push ("laskar", "andrea");
    s.push ("harry pooter", "jk");
    // s.pop(); 
    s.cetak();

     // --- QUEUE ---
    cout << "\n========== QUEUE / ANTRIAN BUKU ==========\n";
    Queue q;
    q.enqueue("sporsi mie ayam sblum mati", "brian");
    q.enqueue("laskar", "andrea");
    q.enqueue("harry pooter", "jk");
    cout << "Sebelum queue:\n";
    q.cetak();
    q.dequeue();
    cout << "Setelah queue:\n";
    q.cetak();
    return 0;
}

bool stack::isEmpty(){
    return top == NULL;
}
void stack::push(string judul,string penulis){
    Nodestack *temp = new Nodestack (judul,penulis);
    if (isEmpty()){
        top=temp;
    }else{
        temp->next=top;
        top=temp;
    }
}
void stack::pop(){
    if(!isEmpty()){
        Nodestack *temp = top;
        top = top->next;
        delete temp;
    }
}

void stack::cetak(){
    Nodestack *temp = top;
    while(temp != NULL){
        cout << "[" << temp->judul << "|" << temp->penulis << "|" << temp->next << "]";

    if(temp == top && temp->next != NULL){
        cout << "\t top\n\t  |\n\t \\/\n";
    }else if (temp == top) {
        cout << "\n\t top\n\t  |\n\t \\/\n";
    }else if(temp->next != NULL){
        cout << "\n\t | \n\t \\/\n";
    }
    temp = temp->next;
    }

}

// ===================== QUEUE =====================


bool Queue::isEmpty() { return front == NULL; }

void Queue::enqueue(string judul, string penulis) {
    NodeQueue *temp = new NodeQueue(judul, penulis);
    if (isEmpty()) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void Queue::dequeue() {
    if (!isEmpty()) {
        NodeQueue *temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
    } else {
        cout << "Queue kosong!\n";
    }
}

void Queue::cetak() {
    if (isEmpty()) {
        cout << "Queue kosong!\n";
        return;
    }
    NodeQueue *temp = front;
    cout << "FRONT --> ";
    while (temp != NULL) {
        cout << "[" << temp->judul << "|" << temp->penulis << "]";
        if (temp->next != NULL) cout << " --> ";
        temp = temp->next;
    }
    cout << " <-- REAR\n";
}