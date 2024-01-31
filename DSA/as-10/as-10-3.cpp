#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    Node *front;
    Node *rear;
};

void enqueue(struct Queue *q, int x) {
    Node *n = new Node;
    if (n == nullptr) {
        cout << "Queue Overflow" << endl;
        return;
    }
    n->data = x;
    n->next = nullptr;

    if (q->front == nullptr) {
        q->front = n;
        q->rear = n;
        n->next = n;
    } else {
        q->rear->next = n;
        q->rear = n;
        n->next = q->front;
    }

    cout << "Enqueued: " << q->rear->data << " ";
}

bool isEmpty(struct Queue *q) {
    return q->front == nullptr;
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        cout << "Queue is already empty" << endl;
        return 0;
    }

    Node *temp = q->front;
    int x = temp->data;

    if (q->front == q->rear) {
        q->front = nullptr;
        q->rear = nullptr;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front;
    }

    delete temp;
    return x;
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        cout << "Queue is Empty" << endl;
        return;
    }

    Node *n = q->front;
    cout << "front -> ";
    do {
        cout << n->data << " -> ";
        n = n->next;
    } while (n != q->front);

    cout << "rear" << endl;
}

int main() {
    struct Queue *q = new Queue;
    q->front = nullptr;
    q->rear = nullptr;

    enqueue(q, 5);
    enqueue(q, 4);
    enqueue(q, 3);
    enqueue(q, 8);
    enqueue(q, 3);

    display(q);

    cout << "Dequeued: " << dequeue(q) << endl;
    cout << "Dequeued: " << dequeue(q) << endl;
    display(q);

    delete q;
    return 0;
}
