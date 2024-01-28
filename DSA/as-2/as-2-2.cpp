#include <iostream>
using namespace std;

void fn(int n){
    if(n==0)
        return;
    cout<<n<<endl;
    fn(n-1);
    return;
}

int main(){

    fn(10);

    return 0;
}