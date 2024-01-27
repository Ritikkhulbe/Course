#include <iostream>
using namespace std;

int max_two(int a, int b){
    if(a>=b)
        return a;
    else
        return b;
}

int main(){
    
    int a,b;
    cin>>a>>b;

    cout<<max_two(a,b)<<endl;

    return 0;
}