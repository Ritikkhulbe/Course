#include <iostream>
using namespace std;

class Example{
    public:
    int n;
    char c;
    Example(){
        n = 0;
        c = 'a';
    }
    Example(int a, char s){
        n = a;
        c = s;
    }
    Example operator +(const Example& x){
        Example t;
        t.n = n + x.n;
        t.c = x.c;

        return t;
    }
};

int main(){

    Example a(23,'f'), b(12,'b'), c;

    c = a+b;
    cout<<c.n<<" "<<c.c<<endl;

    return 0;
}