#include <iostream>
using namespace std;

struct Tree {
    int data;
    Tree* left;
    Tree* right;

    Tree(int value) : data(value), left(nullptr), right(nullptr) {}
};

void Insert(struct Tree *&root, int key){
    Tree* t = root, *p, *r;

    if(!root){
        p = new Tree(key);
        root = p;
        return;
    }
    while(t!=nullptr){
        r = t;
        if(key < t->data){
            t = t->left;
        }else if(key > t->data){
            t = t-> right;
        }else return;
    }

    p = new Tree(key);
    if(key < r->data){
        r->left = p;
    }else{
        r->right = p;
    }
    return;
}
void Inorder(struct Tree *root){
    if(!root) return;

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

int main() {
    Tree* root = nullptr;
    int arr[] = {50, 70, 60, 20, 90, 10, 40, 100};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i<n;i++){
        Insert(root, arr[i]);
    }

    cout<<"Tree inorder traversal :"<<endl;
    Inorder(root);
    cout<<"\n";
}