#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Queue{
    Node *front;
    Node *rear;
};

void enqueue(struct Queue *q, int x){
    Node *n = new Node;
    if(n == nullptr){
        cout<<"Queue Overflow"<<endl;
        return;
    }
    n->data = x;
    n->next = nullptr;
    if(q->front==nullptr){
        q->front = n;
        q->rear = n;
    }else{
        q->rear->next = n;
        q->rear = n;
    }
    return;
}

bool isEmpty(struct Queue *q){
    if(q->front == nullptr){
        return true;
    }
    return false;
}

void display(struct Queue *q){
    if(isEmpty(q)) {
        cout<<"Queue is Empty"<<endl;
        return;
    }
    Node *n = q->front;
    cout << "front -> ";
    while (n != nullptr) {
        cout << n->data << " -> ";
        n = n->next;
    }
    cout << "rear" << endl;
}
int dequeue(struct Queue *q){
    Node* n;
    if(isEmpty(q)) {
        cout<<"Queue does not have any elements to dequeue"<<endl;
        return 0;
    }
    n = q->front;
    q->front = q->front->next;
    int x = n->data;
    delete n;
    return x;
}


int main(){
    struct Queue *q = new Queue;
    q->front=nullptr;
    q->rear= nullptr;

    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        enqueue(q,x);
    }
    display(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);

    display(q);


    delete[] q;
    return 0;
}