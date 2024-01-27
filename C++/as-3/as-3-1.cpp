#include <iostream>
#include <string>
using namespace std;

int main(){

    string str, s, a;
    cin>>str;
    bool arr[26] = {0};
    
    for (int x=0; x<str.length(); x++)
        s += tolower(str[x]);

    for(auto i: s){
        if(arr[i-'a']){
            cout<< i <<" ";
        }else{
            arr[i-'a'] = 1;
        }
    }

    return 0;
}