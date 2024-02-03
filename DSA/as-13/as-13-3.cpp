#include <iostream>
using namespace std;

int minNode(int h){
    if(h <= 0) return 1;
    if(h == 1) return 2;
    return (minNode(h-1) + minNode(h-2) + 1);
}

int main(){
    int h;
    cout<<"Enter the height of the AVL tree : ";
    cin >> h;

    cout<<minNode(h)<<endl;
    return 0;
}