/*
    Ricy Rifani Putra - A11.2025.16464
    Selasa & Kamis, 3 & 5 Maret 2026 - h.2.1
    Review Dasar Pemrograman
*/

#include<iostream>
using namespace std;

    typedef struct anggota {
        string nama, asal_kota, tipe_kartu;
        int tahun_masuk, masa_keanggotaaan;
    }komunitas;

int main()
{
    string nama1, nama2, nama3, asal_kota1, asal_kota2, tipe_kartu;
    int tahun_masuk, masa_keanggotaaan;
    string namaAnggota[100], asal_kota[100];

    int i, n;
    komunitas sepeda[100];
    sepeda[0].nama = "Alex";
    sepeda[0].tahun_masuk = 2000;
    

    // Input
    cout << "Berapa penyewa yang akan diinput? "; cin >> n;
    for(i=0; i<n; i++){
        cout << "Penyewa ke-" << i+1 << endl;      // saat print i+1 namun i tetap, misal print 1 namun i=0
        cout << "Masukan nama = "; cin >> sepeda[i].nama;
        cout << "Tahun masuk = "; cin >> sepeda[i].tahun_masuk;
        cout << "Asal kota = "; cin >> sepeda[i].asal_kota;

        sepeda[i].masa_keanggotaaan = 2026 - sepeda[i].tahun_masuk;
        if(sepeda[i].masa_keanggotaaan == 2)
            sepeda[i].tipe_kartu = "Silver";
        else if(sepeda[i].masa_keanggotaaan >=3 && sepeda[i].masa_keanggotaaan <=5)
            sepeda[i].tipe_kartu = "Gold";
        else if(sepeda[i].masa_keanggotaaan > 5)
            sepeda[i].tipe_kartu = "Platinum";
        else
            sepeda[i].tipe_kartu = "-";
    }

    // OUTPUT
    cout << "|==================================================================|\n";
    cout << "| Nama \t | Tahun Masuk | Asal kota | Masa keanggotaan | Tipe kartu | \n";
    cout << "|==================================================================|\n";
    for(i=0; i<n; i++) {
        cout << "| " << sepeda[i].nama << "\t| " 
             << sepeda[i].tahun_masuk << " \t\t| " 
             << sepeda[i].asal_kota << " \t| " 
             << sepeda[i].masa_keanggotaaan << " tahun \t| " 
             << sepeda[i].tipe_kartu  << " \t|\n";     
    }
    cout << "|==================================================================|\n";
    // MAX MASA KEANGGOTAAN
    int maxMasa = 0, indexMaxMasa;
    for(i=0; i<n; i++) {
        if(sepeda[i].masa_keanggotaaan > maxMasa){
            maxMasa = sepeda[i].masa_keanggotaaan;
            indexMaxMasa = i;
        }
    }

    cout << "Masa keanggotaan terlama adalah " << sepeda[indexMaxMasa].nama << " sudah " << maxMasa << " tahun\n ";

    // CARI NAMA    
    string cariNama;
    bool ketemu = false;

    cout << "Pencarian berdasarkan nama: "; cin >> cariNama;
    for(i=0; i<n; i++) {
        if(sepeda[i].nama == cariNama) {
            ketemu = true;
            // copy dari ouput
            cout << "|==================================================================|\n";
            cout << "| Nama \t | Tahun Masuk | Asal kota | Masa keanggotaan | Tipe kartu | \n";
            cout << "|==================================================================|\n";
            cout << "| " << sepeda[i].nama << "\t| " 
                 << sepeda[i].tahun_masuk << " \t\t| " 
                 << sepeda[i].asal_kota << " | " 
                 << sepeda[i].masa_keanggotaaan << " \t\t| " 
                 << sepeda[i].tipe_kartu  << " |\n"; 

              cout << "|==================================================================|\n";
              break;
            }
        }
        if(!ketemu) {
            cout << "Data tidak ditemukan.\n";
        }
    return 0;
}