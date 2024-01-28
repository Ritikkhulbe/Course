#include <iostream>
using namespace std;

int main(){

    int baseAddress = 100;
    int elementSize = 1;
    int rows = 10;

    int i = 8;
    int j = 6;
    //So address of A[1700] will be 

    int ans = baseAddress + ( (( i-1 )*rows) + (j-1) ) * elementSize;

    cout<<ans<<endl;

    return 0;
}