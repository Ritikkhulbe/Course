#include <iostream>
using namespace std;


int main(){
    const int n =3, m=4;
    int A[n][m] =  {{1,2,3,4},{5,1,2,3},{9,5,1,2}};

    int B[m][n];
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            B[j][i] = A[i][j];
        }
    }

    cout<<"Matrix A : \n"<<endl;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Matrix B : \n"<<endl;
    for(int i = 0; i < m;i++){
        for(int j = 0; j < n;j++){
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}