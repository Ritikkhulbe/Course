#include <iostream>
#include <string>
using namespace std;

int main(){

    string str;
    cin>>str;

    int vowels=0, consonants=0;

    for(auto s: str){
        if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u')
            vowels++;
        else
            consonants++;
    }

    cout<<"Vowels: "<<vowels<<endl<<"Consonants: "<<consonants<<endl;


    return 0;
}