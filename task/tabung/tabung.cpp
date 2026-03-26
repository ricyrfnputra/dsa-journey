/*
Judul       : OOP
Tanggal     : 26-03-2026
dibuat oleh : Ricy Rifani Putra
Nim         : A11.2025.16464 
*/

#include<iostream>
using namespace std;

class Tabung{
    float jari_jari, tinggi;
    const float phi = 3.14;

    public:
    // konstruktor default
    Tabung(){
        cout << "Tabung terbentuk \n";
    }
    // konstruktor dengan inputan, set var.jari_jari dengan inpurab r dan var.tinggi dengan inputan t
    Tabung(float r, float t){
        jari_jari = r;
        tinggi = t;
    }

    float volume();
    float luas_permukaan();
    void setJariJari(float jari_jari);
    void setTinggi(float tinggi);
    float getJariJari();
    float getTinggi();
};

int main()
{
    Tabung t1;

    t1.setJariJari(10);
    t1.setTinggi(10);

    cout << "Tabung t1 \n";
    cout << "jari_jari = " << t1.getJariJari() << endl;
    cout << "Tinggi = " << t1.getTinggi() << endl;
    cout << "Volume = " << t1.volume() << endl;
    cout << "Luas_permukaan = " << t1.luas_permukaan() << endl;
    cout << endl;

    Tabung t2(42, 11);

    cout <<"Tabung t2 \n";
    cout << "Jari jari = " << t2.getJariJari() << endl;
    cout << "Tinggi = " << t2.getTinggi() << endl;
    cout << "Volume = " << t2.volume() << endl;
    cout << "Luas_permukaan = " << t2.luas_permukaan() << endl;
    cout << endl;


    return 0;
}

float Tabung::volume(){
    return  phi * jari_jari * jari_jari * tinggi;
}

float Tabung::luas_permukaan(){
    return 2 * 3.14 * jari_jari * (jari_jari + tinggi);
}

void Tabung::setJariJari(float jari_jari){
    this->jari_jari = jari_jari;
    // set var.jari_jari milik class denhan inputan jari_jari
}

void Tabung::setTinggi(float tinggi){
    this->tinggi = tinggi;
    // set var.tinggi milik class dengan inputan tinggi
}

float Tabung::getJariJari(){
    return jari_jari;
}

float Tabung::getTinggi(){
    return tinggi;
}

