#include <iostream>
using namespace std;

int main(){
    const int n =3, m=4;
    int arr[n][m] =  {{1,2,3,4},{5,1,2,3},{9,5,1,2}};

    for(int i = 1; i < n;i++){
        for(int j = 1; j < m;j++){
            if(arr[i][j]!=arr[i-1][j-1]){
                cout<<"It's not a Tooeplitz Matrix"<<endl;
                return 0;
            }
        }
    }

    cout<<"The given matrix is a Toeplitz Matrix\n"<<endl;
    for(int i = 0; i < n;i++){
        cout<<"\t";
        for(int j = 0; j < m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}