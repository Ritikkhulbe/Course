#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void Append(struct Node *head, int x){
    while(head->next != NULL){
        head = head->next;
    }
    struct Node *q = new Node;
    q->data = x;
    q->next = nullptr;
    head->next = q;
    return;
}

void displayLL(struct Node *head){
    while(head->next != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<head->data<<endl;
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
            p->next = nullptr;  // Set the last node's next pointer to nullptr
        }
    } 
    displayLL(head);
    Append(head, 7);
    displayLL(head);
    Append(head, 9);
    displayLL(head);
    return 0;
}