#include <iostream>
#include <string>
using namespace std;

int main(){

    string str;
    cin>>str;

    char a;
    cin>>a;

    for(int i = 0; i < str.length() ; i++){
        if(str[i]==a){
            cout<<"Character found at index : "<< i << endl;
            return 0;
        }
    }
    cout<<"Character not found!"<<endl;


    return 0;
}