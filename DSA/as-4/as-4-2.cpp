#include <iostream>
using namespace std;

bool isSorted(int arr[]){
    for(int i = 0; i<9 ; i++){
        if(arr[i]>arr[i+1])
            return false;
    }
    return true;
}

void sortArr(int arr[]){
    for(int i = 0;i<9;i++){
        for(int j = i+1;j<10;j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout<<"Sorted array is :"<<endl;
    for(int i = 0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    
    int arr[10] = {2,4,12,4,5,43,64,12,21,4};

    if(isSorted(arr)){
        cout<<"The given array is sorted"<<endl;
    }else{
        cout<<"The given array is not sorted\n\nSorting...\n\n";
        sortArr(arr);
    }

    return 0;
}