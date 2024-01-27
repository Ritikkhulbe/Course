#include <iostream>
using namespace std;

class Factorial{
    public:
    int n;

    Factorial(){
        cin>>n;
    }
    int fact(){
        int temp=1, i=1;
        while(i<=n){
            temp*=i;
            i++;
        }
        return temp;
    }
};

int main(){

    Factorial a;
    cout<< a.fact() <<endl;
    return 0;
}