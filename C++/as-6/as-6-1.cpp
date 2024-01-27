#include <iostream>
using namespace std;

int area(int a){
    return a*a;
}

int area(int a, int b){
    return a*b;
}

int main(){
    int x,y,z;

    cout<<"Enter side of the square: ";
    cin>>x;
    cout<<"Area of the square is: "<<area(x)<< endl;

    cout<<"Enter sides of the rectangle: ";
    cin>>y>>z;
    cout<<"Area of the rectangle is: "<<area(y,z)<< endl;

    return 0;
}