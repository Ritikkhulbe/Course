#include <iostream>
 using namespace std;

 int main(){
    int a,b,c;
    cout<<"Enter two numbers: "<<endl;
    cin >> a >> b;
    try{
        if(b==0){
            throw 401;
        }
        c = a/b;
        cout<<"a / b = " << c << endl;
    } catch(int e) {
        cout<<"Division by zero not possible"<<endl;
    }
    return 0;
 }