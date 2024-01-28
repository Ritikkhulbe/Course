#include <iostream>
#include <limits.h>
using namespace std;

int main(){
    char str[] = "Hello this is the sentence for calculating min and max length of any word in the string";

    int min = INT_MAX;
    int max = INT_MIN;

    int currCount = 0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!=' '){
            currCount++;

            if(currCount>max){
                max = currCount;
            }
        }else{
            if(currCount<min){
                min = currCount;
            }
            currCount=0;
        }
    }
    cout<<"\n\nThe max length word is : "<<max<<"\nThe min length word is : "<<min<<"\n\n"<<endl;
    return 0;
}