#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int low = 0, high=n;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(mid*mid == n){
            cout << "square root of "<<n<<" is : "<< mid;
            return 0;
        }else if(mid*mid > n){
            high = mid-1;
        }else{
            low = mid + 1;
        }
    }
    cout<<n<<" does not have an integer square root"<<endl;
    return 0;
}