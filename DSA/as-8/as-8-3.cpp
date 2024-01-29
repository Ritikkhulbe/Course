#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void displayLL(struct Node *head){
    while(head->next != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<head->data<<endl;
}

Node* Insert(struct Node *head, int pos, int x){
    struct Node* first = head;
    if(pos==0){
        struct Node *q = new Node;
        q->data = x;
        q->next = head;
        head = q;
        return head;
    }
    else {
        pos--;
        while(pos--){
            head = head->next;
        }
        struct Node *q = new Node;
        q->data = x;
        q->next = head->next;
        head->next = q;
    }
    return first;
}


int main(){
    struct Node *head, *p, *q;
    head = new Node;
    p = head;
    for(int i = 1 ; i<= 5;i++){
        p->data = i;
        if (i < 5) {
            q = new Node;
            p->next = q;
            p = q;
        } else {
            p->next = nullptr; 
        }
    } 

    displayLL(head);
    head = Insert(head, 3, 10);
    displayLL(head);
    head = Insert(head, 0, 20);
    displayLL(head);
    return 0;
}