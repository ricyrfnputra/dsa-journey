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
 
int main(){
 
    cout << " stack / tumpukan buku\n";
    stack s;
 
    s.push ("sporsi mie ayam sblum mati", "brian");
    s.push ("laskar", "andrea");
    s.push ("harry pooter", "jk");
    s.pop();
    s.cetak();
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
    if(isEmpty()){
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