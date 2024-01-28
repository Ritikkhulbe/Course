#include <iostream>
using namespace std;

int main(){
    int *n;
    n = new int[5];
    for(int i = 0; i< 5;i++){
        cin>>n[i];
    }
    int sum = 0;
    for(int i = 0;i<5;i++){
        sum += n[i];
    }
    cout<<"Sum of the elements in the array : "<<sum<<endl;

    delete[] n;
    n = NULL;
    return 0;
}