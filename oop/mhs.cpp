//nama  : Ricy Rifani Putra
//nim   : A11.2025.16464
#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
private:
    string nama, nim;
    float ipk;

    public:
    void cetakData(Mahasiswa mhs);
    void inputData(Mahasiswa &mhs);
    string getNama(); 
    string getNim();
    float getIpk();
    void setipk(float ipk);
};

void cetaksemuaMhs(Mahasiswa m[], int n);
void sortingdesc(Mahasiswa m[], int n);

int main() {

    Mahasiswa mm[40];
    int jml_mahasiswa; 
    cout << "Masukkan jumlah mahasiswa: ";
    Mahasiswa mhs;
    mhs.inputData(mhs);
    mhs.cetakData(mhs);
    cin>>jml_mahasiswa;
    for (int i = 0; i < jml_mahasiswa; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        mm[i].inputData(mm[i]);
    }

    //cetak semua data mahasiswa bentuk tabel
    cetaksemuamhs(mm, jml_mahasiswa);
    //proses sorting ipk descending
    sortingdesc(mm, jml_mahasiswa);

    int pil;
    char lanjut;
    do{
        cout << "menu:\n1. ganti IPK \n2. cari berdasarkan nama\n3.cari berdasarkan nim\nMasukkan pilihan =";
        cin >> pil;

        if (pil==1){

        }else if (pil==2){

        }else {
            cout << "pilihan tidak valid" << endl;
        }

    }while(lanjut=='y' || lanjut=='Y');
    return 0;
}

void sortingdesc(Mahasiswa m[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (m[j].getIpk() < m[j + 1].getIpk()) {
                Mahasiswa temp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = temp;
            }
        }
    }
}

void cetaksemuamhs(Mahasiswa m[], int n) {
    cout << "Daftar Mahasiswa" << endl;
    cout << "No\tNama\tNIM\tIPK" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << m[i].getNama() << "\t" << m[i].getNim() << "\t" << m[i].getIpk() << endl;
    }
}

void Mahasiswa::inputData(Mahasiswa &mhs) {
    cout << "Masukkan Nama: ";
    getline(cin, mhs.nama);
    cout << "Masukkan NIM: ";
    getline(cin, mhs.nim);
    //jika ipk diluar 0-4 maka meminta input ulang
    do{
        cout << "Masukkan IPK (0-4): ";
        cin >> mhs.ipk;
        if (mhs.ipk < 0 || mhs.ipk > 4) {
            cout << "IPK harus antara 0 dan 4. Silakan coba lagi." << endl;
        }
    }
    while (mhs.ipk < 0 || mhs.ipk > 4);
}

void Mahasiswa::cetakData(Mahasiswa mhs) {
    cout << "Nama: " << mhs.nama << endl;
    cout << "NIM: " << mhs.nim << endl;
    cout << "IPK: " << mhs.ipk << endl;
}

string Mahasiswa::getNama() {
    return nama;
}

string Mahasiswa::getNim() {
    return nim;
}

float Mahasiswa::getIpk() {
    return ipk;
}

void Mahasiswa::setipk(float ipk) {
    this->ipk = ipk;
}

