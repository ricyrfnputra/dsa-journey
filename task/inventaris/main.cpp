#include<iostream>
using namespace std;
    class Barang{
        private:
            string kodeBarang, namaBarang;
            int harga, stok;

        public:
            void input(){
                cout << "Masukan kode barang : "; cin >> kodeBarang;
                cout << "Masukan nama barang : "; cin >> namaBarang;
                cout << "Masukan Harga Barang : "; cin >> harga;
                cout << "Masukan Jumlah Stok : "; cin >> stok;
            }

        string getKode() {return kodeBarang; }
        string getNama() {return namaBarang; }
        int getHarga() {return harga; }
        int getStok() {return stok; }
    };


    void sortingHargaAsc()

int main()
{
    int n;
    cout << "Masukan jumlah jenis barang: "; cin >> n;

    Barang ListBarang[100];

    for(int i = 0; i < n; i++){
        cout << "\nData Barang Ke-" << i + 1 << endl;
        ListBarang[i].input();    
    }

    

}