#include <iostream>
using namespace std;

int main ()
{
    int sum;
    for(int n=1; n<=500;n++) {   
        sum = 0;
        for(int i = 1; i < n; i++){
            if(n % i == 0)
                sum = sum + i;
        }
        if(sum == n)
            cout << n << " ";
    }
    
    return 0;
}