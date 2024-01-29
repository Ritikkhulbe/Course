#include <iostream>
using namespace std;

struct Element{
    int row;
    int col;
    int val;
};

void display(struct Element M[]){
    int k = 1;
    for(int i = 0; i < M[0].row ; i++){
        for(int j = 0; j < M[0].col; j++){
            cout<<"\t";

            if(k>M[0].val){
                cout<<"0";
                continue;
            }

            if(M[k].row-1 == i && M[k].col-1 == j){
                cout<< M[k].val;
                k++;
            }else{
                cout<<"0";
            }
        }
        cout<<endl;
    }
}

int main(){
    Element A[] = {{4,4,6},{1,3,9},{2,2,8},{2,4,1},{3,1,4},{3,3,2},{4,4,3}};
    Element B[] = {{4,4,5},{1,2,2},{2,1,4},{2,2,2},{3,3,1},{4,1,9}};
    Element C[11] = {0,0,0};
    C[0] = {4,4,11};
    int i = 1, j = 1, k = 1;
    while(i <= A[0].val && j <= B[0].val){
        if(A[i].row < B[j].row || A[i].col < B[j].col)
            C[k++] = A[i++];
        else if(A[i].row > B[j].row || A[i].col > B[j].col)
            C[k++] = B[j++];
        else{
            C[k] = A[i++];
            C[k++].val += B[j++].val;
        }
    }
    while(i <= A[0].val)
        C[k++] = A[i++];
    while(j <= B[0].val)
        C[k++] = B[j++];
    C[0].val = k-1;

    cout<<"A : "<<endl;
    display(A);
    cout<<"B : "<<endl;
    display(B);
    cout<<"C : "<<endl;
    display(C);


    return 0;
}