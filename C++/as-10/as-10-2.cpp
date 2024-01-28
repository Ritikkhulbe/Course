#include <iostream>
#include <fstream>
using namespace std;


int main(){
    string a;
    int b,c;
    ifstream file1;
    file1.open("file1.txt");
    cout<<"\nName\tClass\tAge\n\n";
    while(!file1.eof()){
        file1 >> a >> b >> c;
        cout<<a<<"\t"<<b<<"\t"<<c<<endl;
    }
    file1.close();
    return 0;
}