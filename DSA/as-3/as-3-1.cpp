#include <iostream>
using namespace std;

int fnSum(int n){
    if(n==0)
        return 0;
    return fnSum(n-1)+n;
}

int main(){

    cout<<"Sum is "<<fnSum(20)<<endl;

    return 0;
}