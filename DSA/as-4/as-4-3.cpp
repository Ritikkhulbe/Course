#include <iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    int key = 28;

    int linearCounter = 0;
    for(int i = 0;i<30;i++){
        
        linearCounter++;

        if(arr[i]==key){
            cout<<"Key found at index: "<<i<<endl;
            break;
        }
    }

    int binaryCounter = 0;
    int low = 0, high = 27;
    while(low<high){

        binaryCounter++;

        int mid = low + (high-low)/2;

        if(arr[mid] == key){
            cout<<"Key found at index : "<<mid;
        }else if(arr[mid] > key){
            high = mid - 1;
        }else{
            low = mid + 1;
        }

    }

    cout<<"Linear Counter took : " <<linearCounter<<" iterations\nBinary Counter took : "<<binaryCounter<<" iterations"<<endl;

    return 0;
}