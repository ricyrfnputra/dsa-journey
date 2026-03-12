#include<iostream>
using namespace std;

class Luas 
{
        public:
        int sisi;

        int persegi(int sisi)
        {
            return sisi*sisi;
        }
}; 

Luas L;

int main()
{
    int Hasil;
    L.sisi = 10;
    Hasil = L.persegi(L.sisi);
    cout << Hasil << endl;

    return 0;
}