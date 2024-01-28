#include <iostream>
using namespace std;

int main(){

    char str[] = "hgsAF782Jadi*71j&j2e@";
    int lowercase = 0, uppercase = 0, num = 0, special = 0;


    for(int i = 0; str[i] != '\0'; i++){
        if(str[i]>=97 && str[i]<=122)
            lowercase++;
        else if (str[i]>=65 && str[i]<=90)
            uppercase++;
        else if (str[i]>=48 && str[i]<=57)
            num++;
        else
            special++;
    }


    cout<<"The given string has the following number of characters:\nLower Case : "<<lowercase;
    cout<<"\nUpper Case : "<<uppercase<<"\nNumerical Characters : ";
    cout<<num<<"\nSpecial Characters : "<<special<<endl;

    return 0;

}