/*
    Nama    : Ricy Rifani Putra
    Nim     : A11.2025.16464
    Materi  : Class & Object
*/

#include<iostream>
using namespace std;

    class PersegiPanjang{
        // Atribut, acces modifier nya private
        float panjang, lebar;

        public:
        // Behaviour atau method
        PersegiPanjang(){   // konstruktor default
            cout << "Persegi panjang terbentuk\n";
        }
        PersegiPanjang(float p, float l){   // konstruktor inputansni
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

int main()
{

    PersegiPanjang pp1; // memanggil konstruktor default
    // ppl.panjang = 10; //ppl.lebar = 10; // tidak boleh langsung memanggil, harus set di atas main (setter/getter).
    pp1.setLebar(10);   // memanggil prosedur boleh sendirian
    pp1.setPanjang(10);
    cout << "Persegi panjang pp1\nPanjang = " << pp1.getPanjang() << "\nLebar = " << pp1.getLebar() << endl;
    // memanggil fungsi harus di dalam cout atau di variabel
    pp1.gambar();
    
    PersegiPanjang pp2(42, 11); // memanggil konstruktor inputan
    float panjangPp2 = pp2.getPanjang();
    float lebarPp2 = pp2.getLebar();
    cout << "Persegi panjang pp2\nPanjang = " << panjangPp2 << "\nLebar =" << lebarPp2 << endl; 

    pp2.gambar();
    return 0;
}
// Gambar
void PersegiPanjang::gambar(){
    for(int i=0; i<lebar; i++){
        for(int j=0; j<panjang; j++) {
            if(i==0 || i==lebar-1 || j==0 || j==panjang-1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}
// Luas
float PersegiPanjang::luas() {
    return panjang*lebar;
}
// Keliling
float PersegiPanjang::keliling(){
    return 2*(panjang+lebar);
}
//Panjang
void PersegiPanjang::setPanjang(float panjang){
    this->panjang = panjang;
    // Set var.panjang milik class dengan inputan panjang
    // panjang = p. jika inputan (float p)
}
void PersegiPanjang::setLebar(float lebar){
    this->lebar = lebar;
    // Set var.panjang milik class dengan inputan panjang
}
float PersegiPanjang::getPanjang(){
    return panjang;

}
float PersegiPanjang::getLebar(){
    return lebar;
}