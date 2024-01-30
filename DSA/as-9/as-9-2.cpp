#include <iostream>
using namespace std;

struct Stack{
    int top;
    int size;
    int *S;
};

void push(struct Stack *&s, int x){
    if(s->top==s->size-1){
        cout<<"Overflow"<<endl;
        return;
    }

    s->S[++s->top] = x;
    return;
}

int pop(struct Stack *&s){
    if(s->top==-1){
        cout<<"No elements to pop";
        return 0;
    }
    int c = s->S[s->top];
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

void correctStack(struct Stack *&s, int value){
        if(s->top==-1 || s->S[s->top] >= value) push(s, value);
        else{
            int topElement = s->S[s->top];
            pop(s);
            correctStack(s, value);
            push(s, topElement);
        }
}
void sortStack(struct Stack *&s){
    if(s->top != -1){
        int temp = pop(s);
        sortStack(s);
        correctStack(s, temp);
    }
}
int main(){
    struct Stack *s =  new Stack;
    s->size = 100;
    s->top = -1;
    s->S = new int[s->size];

    int n;
    cin >> n;


    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        push(s, x);
    }

    display(s);
    sortStack(s);
    cout<<"\nsorting...\n";
    display(s);

    delete[] s->S;
    delete s;
    return 0;
}