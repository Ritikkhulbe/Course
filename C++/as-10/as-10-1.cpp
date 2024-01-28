#include <iostream>
#include <fstream>
using namespace std;

class Student{
    public:
    string name;
    int Class;
    int age;
    Student(string a, int b, int c){
        name=a; Class = b; age=c;
    }
    friend ofstream & operator <<(ofstream& F, const Student& student) {
        F << student.name << "\t";
        F << student.Class << "\t";
        F << student.age << endl;
        return F;
    }
};

int main(){
    Student a("XD", 2, 12);

    ofstream file1;
    file1.open("file1.txt",ios::app);
    file1 << a;

    file1.close();
    return 0;
}