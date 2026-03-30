#include<iostream>

class Trapezoid{
    float topside, bottomside;
    float side1, side2;
    float height;

    public:
    Trapezoid(){
        std::cout << "Trapezoid created \n";
    }

    Trapezoid(float a,float b,float c,float d,float h){
        topside = a;
        bottomside = b;
        side1 = c;
        side2 = d;
        height = h;
    }

    float area();
    float perimeter();
    void setTopSide(float topside);
    void setBottomSide(float bottomside);
    void setSide1(float side1);
    void setSide2(float side2);
    void setHeight(float height);
    float getTopSide();
    float getBottomSide();
    float getSide1();
    float getSide2();
    float getHeight();
};


int main()
{
    Trapezoid t1;

    t1.setTopSide(12);
    t1.setBottomSide(20);
    t1.setSide1(4);
    t1.setSide2(6);
    t1.setHeight(25);

    std::cout << "Trapezoid t1 \n";
    std::cout << "Top Side = " << t1.getTopSide() << std::endl;
    std::cout << "Bottom Side = " << t1.getBottomSide() << std::endl;
    std::cout << "Side 1 = " << t1.getSide1() << std::endl;
    std::cout << "Side 2 = " << t1.getSide2() << std::endl;
    std::cout << "Height = " << t1.getHeight() << std::endl;


    Trapezoid t2(14, 22, 6, 8, 30);

    std::cout << "Trapezoid t2 \n";
    std::cout << "Top Side = " << t2.getTopSide() << std::endl;
    std::cout << "Bottom Side = " << t2.getBottomSide() << std::endl;
    std::cout << "Side 1 = " << t2.getSide1() << std::endl;
    std::cout << "Side 2 = " << t2.getSide2() << std::endl;
    std::cout << "Height = " << t2.getHeight() << std::endl;


    return 0;
}

float Trapezoid::area()
{
    return 1/2 * (topside * bottomside) *  height;
}

float Trapezoid::perimeter()
{
    return topside + bottomside + side1 + side2;
}

void Trapezoid::setTopSide(float topside)
{
    this->topside = topside;
}

void Trapezoid::setBottomSide(float bottomside)
{
    this->bottomside = bottomside;
}

void Trapezoid::setSide1(float side1)
{
    this->side1 = side1;
}

void Trapezoid::setSide2(float side2)
{
    this->side2 = side2;
}

void Trapezoid::setHeight(float height)
{
    this->height = height;
}

float Trapezoid::getTopSide()
{
    return topside;
}

float Trapezoid::getBottomSide()
{
    return bottomside;
}

float Trapezoid::getSide1()
{
    return side1;
}

float Trapezoid::getSide2()
{
    return side2;
}

float Trapezoid::getHeight()
{
    return height;
}

// Just messing around after class 
// Making sure this stuff actually makes sense