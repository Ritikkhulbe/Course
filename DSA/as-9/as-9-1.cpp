#include <iostream>
using namespace std;

struct Stack{
    int top;
    int size;
    char *S;
};

void push(struct Stack *&s, char x){
    if(s->top==s->size-1){
        cout<<"Overflow"<<endl;
        return;
    }

    s->S[++s->top] = x;
    return;
}

char pop(struct Stack *&s){
    if(s->top==-1){
        cout<<"No elements to pop";
        return '~';
    }
    char c = s->S[s->top];
    s->S[s->top--] = ' ';
    return c;
}
void display(struct Stack *s){
    cout<<"Stack : "<<endl;
    cout<<"Top - > ";
    for(int i = s->top;i>=0;i--){
        cout<<s->S[i]<<" ";
    }
    cout<<"-> bottom"<<endl;
}


int main(){
    struct Stack *s =  new Stack;
    s->size = 100;
    s->top = -1;
    s->S = new char[s->size];

    string str;
    cin >> str;

    for(int i = 0;i<str.length();i++){
        push(s, str[i]);
    }

    display(s);
    
    str = "";
    for(int i = s->top;i>=0;i--){
        str += pop(s);
    }

    cout<<str;

    delete[] s->S;
    delete s;
    return 0;
}