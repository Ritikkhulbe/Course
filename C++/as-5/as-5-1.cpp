#include <iostream>
using namespace std;

struct Person{
    string name;
    int age;
};

int main(){
    //to print name of students who can vote
    Person a[5];
    for(int i=0;i<5;i++){
        cin>>a[i].name>>a[i].age;
    }

    for(int i=0;i<5;i++){
        if(a[i].age>=18){
            cout<<a[i].name<<", ";
        }
    }

    return 0;
}