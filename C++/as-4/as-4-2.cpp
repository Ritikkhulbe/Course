#include <iostream>
#include <cmath>
using namespace std;

void calc(int a, char s, int b){
        switch (s)
    {
    case '+':
        cout<<a+b<<endl;
        break;
    case '-':
        cout<<a-b<<endl;
        break;
    case '*':
        cout<<(a*b)<<endl;
        break;
    case '/':
        cout<<(a/b)<<endl;
        break;
    case '^':
        cout<<pow(a,b)<<endl;
        break;
    default:
        cout<<endl<<"Undefined expression entered"<<endl;
        break;
    }
}

int main(){

    int a,b;
    char s;
    cout<<"Enter first number:"<<endl;
    cin>>a;
    cout<<"Enter expression:"<<endl;
    cin>>s;
    cout<<"Enter second number:"<<endl;
    cin>>b;
    cout<<"The answer of the given inputs are: ";

    calc(a,s,b);

    return 0;
}