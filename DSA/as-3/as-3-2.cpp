#include <iostream>
using namespace std;

int main(){

    int baseAddress = 1020;
    int elementSize = 2;
    int lowerBound =1300;
    int i = 1700;

    //So address of A[1700] will be 

    int ans = baseAddress + ( i - lowerBound ) * elementSize;

    cout<<ans<<endl;

    return 0;
}