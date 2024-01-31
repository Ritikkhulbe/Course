#include<iostream>
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
        return '~';
    }
    int c = s->S[s->top];
    s->S[s->top--] = ' ';
    return c;
}
bool isFull(struct Stack *s){
    if(s->top>=s->size-1) return true;
    return false;
}
void display(struct Stack *s, struct Stack *s2){
    cout<<"Queue : "<<endl;
    cout<<"Front - > ";
    for(int i = s->top;i>=0;i--){
        cout<<s->S[i]<<" ";
    }
    for(int i = 0;i<=s2->top ;i++){
        cout<<s2->S[i]<<" ";
    }
    cout<<"-> Rear"<<endl;
}

bool invert(struct Stack *&s, struct Stack *&q){
    if(q->top!=-1) {
        cout<<"Cannot invert"<<endl;
        return false;
    }
    while(s->top >= 0){
        push(q,pop(s));
    }
    return true;
}
void enqueue(struct Stack *&s,struct Stack *&q, int x){
    if(isFull(s)){
        bool success = invert(s,q);
        if(!success){
            cout<<"Cannot Enqueue";
            return;
        }
    }
    push(s, x);
}
void dequeue(struct Stack *s, struct Stack *q){
    if(q->top==-1){
        bool success = invert(s, q);
    }
    cout<<"dequeued : "<<pop(q)<<endl;
}

int main(){
    struct Stack *s = new Stack, *q = new Stack;
    s->size = 100;
    q->size = 100;
    s->top = -1;
    q->top = -1;
    s->S = new int[s->size];
    q->S = new int[q->size];

    enqueue(s,q, 5);
    enqueue(s,q, 2);
    enqueue(s,q, 4);
    enqueue(s,q, 9);

    
    display(q,s);
    dequeue(s,q);
    display(q,s);

    delete[] q,s;
    delete q,s;
}