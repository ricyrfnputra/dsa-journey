#include "header.h"

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