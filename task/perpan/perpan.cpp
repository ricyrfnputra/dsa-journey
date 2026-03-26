#include <iostream>
using namespace std;

class persegiPanjang {
    // atribut, access modifier nya private
    float panjang, lebar;

public:
    // behavior atau method
    persegiPanjang() {
        cout << "Persegi panjang terbentuk \n";
    }

    persegiPanjang(float p, float l) {
        panjang = p;
        lebar = l;
    }

    float luas();
    float keliling();
    void setPanjang(float panjang);
    void setLebar(float lebar);
    float getPanjang();
    float getLebar();
    void gambar();
};

// deskripsi:
int main() {
    persegiPanjang pp1; // membuat objek pp1 dari class persegiPanjang

    // pp1.panjang = 10; tidak boleh langsung memanggil
    pp1.setLebar(10);
    pp1.setPanjang(10);

    cout << "Persegi Panjang pp1 \n Panjang = " << pp1.getPanjang()
         << "\n Lebar = " << pp1.getLebar() << endl << endl;

    pp1.gambar(); // memanggil fungsi gambar

    persegiPanjang pp2(42, 11); // konstruktor inputan
    float panjangPp2 = pp2.getPanjang();
    float lebarPp2 = pp2.getLebar();

    cout << "Persegi Panjang pp2 \n Panjang = " << panjangPp2
         << "\n Lebar = " << lebarPp2 << endl;

    cout << "Luas pp2 = " << pp2.luas() << endl;

    return 0;
}

// DIBAWAH INT MAIN
float persegiPanjang::luas() {
    return panjang * lebar;
}

float persegiPanjang::keliling() {
    return 2 * (panjang + lebar);
}

void persegiPanjang::setPanjang(float panjang) {
    this->panjang = panjang;
}

void persegiPanjang::setLebar(float lebar) {
    this->lebar = lebar;
}

float persegiPanjang::getPanjang() {
    return panjang;
}

float persegiPanjang::getLebar() {
    return lebar;
}

void persegiPanjang::gambar() {
    for (int i = 0; i < lebar; i++) {
        for (int j = 0; j < panjang; j++) {
            if (i == 0 || i == lebar - 1 || j == 0 || j == panjang - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}