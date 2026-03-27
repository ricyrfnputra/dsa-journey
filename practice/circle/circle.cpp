#include<iostream>

    class Circle {
        float jari_jari;
        float const phi = 3.14;
    

    public: 

    Circle(){
        std::cout << "Lingkaran terbentuk \n";
    }

    Circle(float r){
        jari_jari = r;
    }

    float luas();
    float keliling();
    void setJariJari(float jari_jari);
    float getJariJari();
};
    

int main()
{   
    Circle c1;

    c1.setJariJari(7);

    std::cout << "Lingkaran c1 \n";
    std::cout << "jari_jari = " << c1.getJariJari() << std::endl;
    std::cout << "luas = " << c1.luas() << std::endl;
    std::cout << "keliling = " << c1.keliling() << std::endl; 
    
    Circle c2(14);
    std::cout << "Lingkaran c2 \n";
    std::cout << "jari_jari = " << c2.getJariJari() << std::endl;
    std::cout << "luas = " << c2.luas() << std::endl;
    std::cout << "keliling = " << c2.keliling() << std::endl;
    
    return 0;
}

float Circle::luas(){
    return phi * jari_jari * jari_jari;
}

float Circle::keliling(){
    return 2 * phi * jari_jari;
}

void Circle::setJariJari(float jari_jari){
    this->jari_jari = jari_jari;
}

float Circle::getJariJari(){
    return jari_jari;
}