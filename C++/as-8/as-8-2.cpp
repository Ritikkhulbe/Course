#include <iostream>
using namespace std;

class Shape{
    public:
    virtual void area()=0;
};

class Rectangle: public Shape{
    public:
    int l, b;
    Rectangle(int x, int y){
        l=x;
        b=y;
    }

    void area(){
        int arear = l*b;
        cout<<"Area of rectagle = "<<arear<<endl;
    }
};

class Triangle: public Shape{
    public:
    int a, b;
    Triangle(int x, int y){
        a=x;
        b=y;
    }

    void area(){
        float areat = (a*b)*0.5;
        cout<<"Area of triangle = "<<areat<<endl;
    }
};

int main(){
    Rectangle r(6,12);
    Triangle t(4,6);

    Shape *a=&r, *b=&t;

    a->area();
    b->area();
    return 0;
}