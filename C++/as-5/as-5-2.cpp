#include <iostream>
using namespace std;

class Reverse{
    public:
    int n;
    Reverse(){
        cin>>n;
    }
    int reverse_number(){
        int temp = 0, remainder;
        while(n != 0) {
            remainder = n % 10;
            temp = temp * 10 + remainder;
            n /= 10;
        }
        return temp;
    }
};

int main(){

    Reverse a;
    cout<< a.reverse_number() <<endl;
    return 0;
}