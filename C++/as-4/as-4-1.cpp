#include <iostream>
using namespace std;

void checkRightToVote(int a){
    if(a>=18){
        cout<<"The person is eligible to vote!"<<endl;
    }
    else{
        cout<<"The person is not eligible to vote!"<<endl;
    }
}

int main(){
    
    int age;
    cin>>age;

    checkRightToVote(age);

    return 0;
}