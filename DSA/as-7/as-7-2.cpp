#include <iostream>
#include <string>
using namespace std;

struct term{
    int coeff;
    int exp;
};

struct Poly{
    int n;
    struct term *t;
};

void display(struct Poly P){
    int i = 0;
    while(i < P.n){
        if(!P.t[i].coeff) {
            i++;
            continue;
        }
        cout<<P.t[i].coeff;
        if(P.t[i].exp==1){
            cout<<"x"<<P.t[i].exp;
        }
        else if(P.t[i].exp>0){
            cout<<"x^"<<P.t[i].exp;
        }
        cout<<" ";
        i++;
    }
    cout<<endl;
    return;
}

int main(){
    cout<<"enter 2 degree polynomial term(coefficient exponent) for the expression :"<<endl;

    struct Poly p1,p2,p3;
    p1.n = 3;
    p1.t = new term[p1.n];
    p2.n = 3;
    p2.t = new term[p2.n];
    p3.n = p1.n+p2.n;
    p3.t = new term[p3.n];
    for(int i = 0; i < p1.n;i++){
        cin >> p1.t[i].coeff;
        cin >> p1.t[i].exp;
    }
    display(p1);
    for(int i = 0; i < p2.n;i++){
        cin >> p2.t[i].coeff;
        cin >> p2.t[i].exp;
    }
    display(p2);
    int i = 0, j=0, k=0;
    while(i < p1.n && j < p2.n){
        if(p1.t[i].exp > p2.t[j].exp){
            p3.t[k++] = p1.t[i++];
        }else if (p1.t[i].exp < p2.t[j].exp){
            p3.t[k++] = p2.t[j++];
        }else{
            p3.t[k].exp = p1.t[i].exp;
            p3.t[k++].coeff = p1.t[i++].coeff + p2.t[j++].coeff;
        }
    }

    cout<<"The polynomial after addidtion : "<<endl;
    display(p3);

    return 0;
}