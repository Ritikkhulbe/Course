#include <iostream>
 using namespace std;

 int main(){
    int a,b,c;
    cout<<"Enter two numbers: "<<endl;
    cin >> a >> b;
    try{
        if(b==0){
            throw 401;
        }else if(a==0){
            throw 'a';
        }
        c = a/b;
        cout<<"a / b = " << c << endl;
    } catch(int e) {
        cout<<"Division by zero not possible"<<endl;
    } catch(char ch) {
        cout<<"Answer will be Zero"<<endl;
    }
    return 0;
 }