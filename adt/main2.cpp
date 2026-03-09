/*
    Ricy Rifani Putra - A11.2025.16464
    Selasa & Kamis, 3 & 5 Maret 2026 - h.2.1
    Review Dasar Pemrograman
*/

#include <iostream>
using namespace std;

    typedef struct anggota{
        string nama, asal_kota, tipe_kartu;
        int tahun_masuk, masa_keanggotaan;
    }komunitas; //membuat ADT sekalian alias (typedef)

int main()
{
    string nama1, nama2, nama3, asal_kota1, asal_kota2, tipe_kartu;
    int tahun_masuk, masa_keanggotaan;
    string nama_anggota[100], asal_kota_anggota[100];

    komunitas sepeda[100];  // var. sepeda dengan tipe data komunitas
    sepeda[0].nama = "Alex";
    sepeda[0].tahun_masuk = 2000;
    int i, n;
    
    cout << "Berapa penyewa yang akan diinput? "; cin >> n;

    // Input
    for(i=0; i<n; i++){
        cout << "Penyewa ke-" << i+1 << endl;
        cout << "Masukkan nama = ";
        cin >> sepeda[i].nama;
        cout << "Tahun masuk   = ";
        cin >> sepeda[i].tahun_masuk;
        cout << "Asal kota     = ";
        cin >> sepeda[i].asal_kota;

        sepeda[i].masa_keanggotaan = 2026 - sepeda[i].tahun_masuk;
        if(sepeda[i].masa_keanggotaan == 2)
            sepeda[i].tipe_kartu = "Silver";    //aksi hanya 1, maka boleh tanpa {}
        else if(sepeda[i].masa_keanggotaan >=3 && sepeda[i].masa_keanggotaan <=5)
            sepeda[i].tipe_kartu = "Gold";
        else if(sepeda[i].masa_keanggotaan > 5)
            sepeda[i].tipe_kartu = "Platinum";
        else
            sepeda[i].tipe_kartu = "-";
    }

    // Output
    cout << "|====================================================================|\n";
    cout << "| Nama \t| Tahun Masuk \t| Asal Kota \t| Masa Keanggotaan | Tipe Kartu |\n";
    cout << "|====================================================================|\n";

    for(i=0; i<n; i++){
        cout << "| " << sepeda[i].nama << "\t| "
             << sepeda[i].tahun_masuk << "\t\t| "
             << sepeda[i].asal_kota << "\t| "
             << sepeda[i].masa_keanggotaan << "\t\t| "
             << sepeda[i].tipe_kartu << "\t|\n"; //1 line
    }
    cout << "|====================================================================|\n";

    // Max Masa Keanggotaan
    int masaMax = 0, indexMasaMax;
    for(i=0; i<n; i++){
        if(sepeda[i].masa_keanggotaan > masaMax){
            masaMax = sepeda[i].masa_keanggotaan;
            indexMasaMax = i;
        }
    }

    cout << "Masa keanggotaan terlama adalah "
         << sepeda[indexMasaMax].nama
         << " sudah " << masaMax << " tahun\n";

    // Search By Name
    string cariNama;
    bool ketemu = false;

    cout << "Pencarian berdasarkan nama: "; cin >> cariNama;

    for(i=0; i<n; i++){
        if(sepeda[i].nama == cariNama){
            ketemu = true;

            //Copy From Output
            cout << "|====================================================================|\n";
            cout << "| Nama \t| Tahun Masuk | Asal Kota \t| Keanggotaan \t| Tipe Kartu \t |\n";
            cout << "|====================================================================|\n";

            cout << "| " << sepeda[i].nama << "\t| "
                 << sepeda[i].tahun_masuk << "\t| "
                 << sepeda[i].asal_kota << "\t| "
                 << sepeda[i].masa_keanggotaan << " tahun\t| "
                 << sepeda[i].tipe_kartu << "\t|\n";

            cout << "|====================================================================|\n";

            break; // emergency exit
        }
    }

    if(!ketemu) //false
        cout << "Data tidak ditemukan.\n";

    return 0;
}