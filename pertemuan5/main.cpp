/*
    Nim     : A11.2025.16464
    Nama    : Ricy Rifani Putra
    Materi  : Sorting Searching Array Object 
*/
// start header.h
#include<iostream>
using namespace std;

    class Mhs{
        private:    // atribute
        string nim, nama;
        float ipk;

        public: // behavior
        void input();
        void cetak();
        string getNim();    // karena atribut bersifat private
        string getNama();   // maka perlu fungsi getter
        float getIpk();     // agar bisa mengakses atribut nya
        void setIpk(float iipk);
        // karena atribut bersifat private, maka perlu prosedur setter untuk mengisi nilai pada atribut
    };

    void sortingIpkDesc(Mhs m[], int n);
    void cetakSemuaMhs(Mhs m[], int n);
    bool searchNim(string k, int n, Mhs m[]);
    float cariIpkDariNama(string k, int n, Mhs m[]);
    void analisaMhs(Mhs m[], int n);

// start pustaka.cpp
void Mhs::input(){
    cout << "Masukan NIM  = "; cin >> nim;
    cout << "Masukan NAMA = "; cin >> nama;
    cout << "Masukan IPK  = "; cin >> ipk;
}
void Mhs::cetak(){
    cout << "NIM  = " << nim << endl;
    cout << "NAMA = " << nama << endl;
    cout << "IPK  = " << ipk << endl;
}
string Mhs::getNim(){
    return nim;
}
string Mhs::getNama(){
    return nama;
}
float Mhs::getIpk(){
    return ipk;
}
void Mhs::setIpk(float iipk){
    ipk = iipk;
}
void sortingIpkDesc(Mhs m[], int n){
    // bubble sort
    int i, j;
    Mhs temp;
    for(i=0; i<n; i++){
        for(j=0; j<n-i-1; j++){
            if(m[j].getIpk() < m[j+1].getIpk()){
                temp = m[j];
                m[j] = m[j+1];
                m[j+1] = temp;
            }
        }
    }
}
void cetakSemuaMhs(Mhs m[], int n){
    cout << "Urutan terbaru\n| No | NIM \t\t | Nama \t\t\t | IPK \t|\n";
    for(int i=0; i<n; i++){
        cout << "| " << i+1 << " | " << m[i].getNim() << " \t\t| " << m[i].getNama() << " \t\t | " << m[i].getIpk() << " \t|\n";
    }

}
bool searchNim(string k, int n, Mhs m[]){
    //LinearSearch + Break
    bool found = false;
    for(int i=0; i<n; i++){
        if(m[i].getNim() ==k) {
            found = true;
            break;
        }
    }
    return found;
} 

float cariIpkDariNama(string k, int n, Mhs m[]) {
    float ipk_dicari;
    for(int i=0; i<n; i++){
        if(m[i].getNama()==k){
            ipk_dicari = m[i].getIpk();
            break;
        }
    }
    return ipk_dicari;
}
void analisaMhs(Mhs m[], int n) {
    float nMax = 0, nMin = 100, jml = 0, nRata;
    int iMax, iMin;
    for(int i=0; i<n; i++){
        jml += m[i].getIpk();   // jml = jml + m[i].getIpk();
        if(m[i].getIpk() > nMax){
            nMax = m[i].getIpk();
            iMax = i;
        }
        if(m[i].getIpk() < nMin){
            nMin = m[i].getIpk();
            iMin = i;
        }
    }
    cout << "Analisa berdasarkan nilai IPK\n";
    cout << "IPK tertinggi = " << nMax << " diperoleh mahasiswa " << m[iMax].getNama() << endl;
    cout << "IPK terendah = " << nMin << " diperoleh mahasiswa " << m[iMin].getNama() << endl;
    nRata = jml/n;
    cout << "IPK rata-rata = " << nRata << endl; 
}

int main()
{
    Mhs mm[40];
    int jml_mhs;

    cout << "Masukan jumlah mahasiswa = ";
    cin >> jml_mhs;

    for(int i=0; i<jml_mhs; i++){
        cout << "Mahasiswa ke-" << i+1 << endl;
        mm[i].input();
    }

        cout << "| No | NIM \t\t | Nama \t\t\t | IPK \t|\n";
    for(int i=0; i<jml_mhs; i++){
        cout << "| " << i+1 << " | " << mm[i].getNim() << " \t\t| " << mm[i].getNama() << " \t\t | " << mm[i].getIpk() << " \t|\n";
    }

    sortingIpkDesc(mm, jml_mhs);
        cout << "Setelah Sorting IPK Descending\n| No | NIM \t\t | Nama \t\t\t | IPK \t|\n";
    for(int i=0; i<jml_mhs; i++){
        cout << "| " << i+1 << " | " << mm[i].getNim() << " \t\t| " << mm[i].getNama() << " \t\t | " << mm[i].getIpk() << " \t|\n";
    }

    int pil, urutan; // pil 1
    char lanjut;
    float ipk_baru;  // pil 1
    string cari_nim, hasil_cari_nim;    // pill 2
    string nama_mhs; // pil 3

    do{
        cout << "\nPilihan\n1. Update IPK berdasarkan Urutann\t3. Cari IPK Mahasiswa berdasarkan Nama\n2. Cari Mahasiswa berdasarkan NIM\t4. Analisa\nMasukan pilihann =";
        cin >> pil;
        if(pil==1) {
            cout << "Masukan urutan: "; cin >> urutan; // buat variabel
            urutan--; // urutan = urutan - 1;
            cout << "Masukan IPK baru antara 0 sampai 4 = "; cin >> ipk_baru; // buat tipe data 
            mm[urutan].setIpk(ipk_baru);
            cetakSemuaMhs(mm, jml_mhs);
        }else if(pil==2) {
            cout << "Masukan NIM mahasiswa yang ingin dicari = ";
            cin >> cari_nim;
            hasil_cari_nim = (searchNim(cari_nim, jml_mhs, mm) == 1)? "Ada" : "Tidak ada"; // if 1 baris // jika search nim hasilnya 1, maka hasil_cari_nim nilainya "Ada", jika tidak "Tidak ada"
            cout << "Mahasiswa " << cari_nim << " " << hasil_cari_nim << endl;
        }else if(pil==3) {
            cout << "Masukan Nama mahasiswa yang ingin dicari = ";
            cin >> nama_mhs; // buat variabel
            cout << "IPK" << nama_mhs << " = " << cariIpkDariNama(nama_mhs, jml_mhs, mm) << endl;
        }else if(pil==4) {
            analisaMhs(mm, jml_mhs);
        }else{
            cout << "Inputan Anda salah\n";
        }

        cout << "Apakah ingin melanjutkan (y/n)? "; cin >> lanjut;
    }while(lanjut=='y');
    
    return 0;

} 

// start pustaka.cpp

