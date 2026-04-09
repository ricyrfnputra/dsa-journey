/*
Judul       : OOP - Class Mahasiswa
Tanggal     : 09-04-2026
Dibuat oleh : Ricy Rifani Putra
Nim         : A11.2025.16464
*/

#include<iostream>
#include<string>
using namespace std;

class Mhs {
    string nim, nama;
    float ipk;

    public:

    void input();
    void cetak();
    string getNim();
    string getNama();
    float getIpk();
    void setIpk(float ipk);
};

int main()
{
    Mhs m1;

    m1.input();

    cout << "\nData Mahasiswa m1 \n";
    m1.cetak();
    cout << endl;

    cout << "NIM     = " << m1.getNim() << endl;
    cout << "Nama    = " << m1.getNama() << endl;
    cout << "IPK     = " << m1.getIpk() << endl;
    cout << endl;

    m1.setIpk(3.95);
    cout << "IPK setelah diubah = " << m1.getIpk() << endl;

    return 0;
}

void Mhs::input() {
    // Proses untuk menginputkan nim, nama, ipk
    cout << "Masukkan NIM  : "; cin >> nim;
    cout << "Masukkan Nama : "; cin.ignore(); getline(cin, nama);
    cout << "Masukkan IPK  : "; cin >> ipk;
}

void Mhs::cetak() {
    // Mencetak nim, nama, ipk
    cout << "NIM  : " << nim << endl;
    cout << "Nama : " << nama << endl;
    cout << "IPK  : " << ipk << endl;
}

string Mhs::getNim() {
    // Mengembalikan nilai nim
    return nim;
}

string Mhs::getNama() {
    // Mengembalikan nilai nama
    return nama;
}

float Mhs::getIpk() {
    // Mengembalikan nilai ipk
    return ipk;
}

void Mhs::setIpk(float ipk) {
    // Set var. ipk milik class dengan inputan ipk
    this->ipk = ipk;
}