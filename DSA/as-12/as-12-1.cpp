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

void greaterSumTree(struct Tree *root, int *sum){
    if(root == nullptr) return;
    greaterSumTree(root->right, sum);

    *sum = *sum + root->data;
    root->data = *sum - root->data;

    greaterSumTree(root->left, sum);
}
int main() {
    Tree* root = nullptr;

    int n;
    cout<<"Enter numbers for BST: ";
    cin>>n;
    
    for(int i = 0; i<n;i++){
        int x;
        cin>>x;
        Insert(root, x);
    }


    cout<<"Tree inorder traversal :"<<endl;
    Inorder(root);
    cout<<"\n";

    int sum = 0;
    greaterSumTree(root, &sum);

    cout<<"Tree inorder traversal after Greater Sum Tree:"<<endl;
    Inorder(root);
    cout<<endl;

    return 0;
}