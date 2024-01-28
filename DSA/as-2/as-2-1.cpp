#include <iostream>
using namespace std;

void fn(int n){
    if(n==0)
        return;
    fn(n-1);
    cout<<n<<endl;
    return;
}

int main(){

    fn(10);

    return 0;
}