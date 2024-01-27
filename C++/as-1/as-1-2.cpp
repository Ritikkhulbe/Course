#include <iostream>
using namespace std;

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

    float ans;
    switch (s)
    {
    case '+':
        ans = a+b;
        cout<<ans<<endl;
        break;
    case '-':
        ans = a-b;
        cout<<ans<<endl;
        break;
    case '*':
        cout<<(a*b)<<endl;
        break;
    case '/':
        cout<<(a/b)<<endl;
        break;
    
    default:
        cout<<endl<<"Undefined expression entered"<<endl;
        break;
    }

    return 0;
}