/*
    Nim     : A11.2025.16464
    Nama    : Ricy Rifani Putra
    Materi  : Sorting Searching Array Object 
*/
#include "header.h"

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
    cout << endl;

        cout << "Data awal Mahasiswa\n| No | NIM \t\t\t| Nama \t\t\t| IPK \t|\n";
    for(int i=0; i<jml_mhs; i++)
        cout << "| " << i+1 << "  | " << mm[i].getNim() << " \t\t| " << mm[i].getNama() << " \t\t\t| " << mm[i].getIpk() << " \t|\n";
    }
    cout << endl;

    sortingIpkDesc(mm, jml_mhs);
        cout << "Setelah Sorting IPK Descending\n| No | NIM \t\t\t| Nama \t\t\t| IPK \t|\n";
    for(int i=0; i<jml_mhs; i++){
        cout << "| " << i+1 << "  | " << mm[i].getNim() << " \t\t| " << mm[i].getNama() << " \t\t\t| " << mm[i].getIpk() << " \t|\n";
    }

    int pil, urutan; // pil 1
    char lanjut;
    float ipk_baru;  // pil 
    string cari_nim, hasil_cari_nim;    // pill 2
    string nama_mhs; // pil 3

    do{
        cout << "\nPilihan\n1. Update IPK berdasarkan Urutann\t3. Cari IPK Mahasiswa berdasarkan Nama\n2. Cari Mahasiswa berdasarkan NIM\t4. Analisa\nMasukan pilihan = ";
        cin >> pil;
        if(pil==1) {
            cout << "Masukan urutan: "; cin >> urutan; // buat variabel
            urutan--; // urutan = urutan - 1;
            cout << "Masukan IPK baru antara 0 sampai 4 = "; cin >> ipk_baru; // buat tipe data 
            mm[urutan].setIpk(ipk_baru);

            
            sortingIpkDesc(mm, jml_mhs);    
            
            cetakSemuaMhs(mm, jml_mhs);
        }else if(pil==2) {
            cout << "Masukan NIM mahasiswa yang ingin dicari = ";
            cin >> cari_nim;
            cout << endl;
            hasil_cari_nim = (searchNim(cari_nim, jml_mhs, mm) == 1)? "Ada" : "Tidak ada"; // if 1 baris // jika search nim hasilnya 1, maka hasil_cari_nim nilainya "Ada", jika tidak "Tidak ada"
            cout << "Mahasiswa dengan NIM : " << cari_nim << " " << hasil_cari_nim << endl;
        }else if(pil==3) {
            cout << "Masukan Nama mahasiswa yang ingin dicari = ";
            cin >> nama_mhs; // buat variabel
            cout << endl;
            cout << "IPK Mahasiswa/i atas nama " << nama_mhs << " = " << cariIpkDariNama(nama_mhs, jml_mhs, mm) << endl;
        }else if(pil==4) {
            analisaMhs(mm, jml_mhs);
        }else{
            cout << "Inputan Anda salah\n";
        }

        cout << "Apakah ingin melanjutkan (y/n)? "; cin >> lanjut;
        if(lanjut=='n'){
            cout << endl;
            cout << "Pencarian Data Selesai!\n";
            cout << "Terima kasih atas Kerja Keras nya *_*";
        }
    }while(lanjut=='y');
    
    return 0;

}


