#include <iostream>
#include <algorithm>
using namespace std;
class Node {
public:
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
public:
    Node* root;

    AVLTree() : root(nullptr) {}

    int getHeight(Node* node) {
        if (!node) return 0;
        return node->height;
    }

    int getBalance(Node* node) {
        if (!node) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        if(root == y){
            root = x;
        }

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        if(root == x){
            root = y;
        }
        return y;
    }


    Node* insert(Node* p, int key) {
        if (!p) return new Node(key);

        if (key < p->key) {
            p->left = insert(p->left, key);
        } else if (key > root->key) {
            p->right = insert(p->right, key);
        }

        p->height = 1 + max(getHeight(p->left), getHeight(p->right));

        int balance = getBalance(p);

        // Left Heavy
        if (balance == 2) {
            if (getBalance(p->left) == 1) {
                return rotateRight(p);
            } else if(getBalance(p->left) == -1){
                p->left = rotateLeft(p->left);
                return rotateRight(p);
            }
        }

        // Right Heavy
        if (balance == -2) {
            if (getBalance(p->right) == -1) {
                return rotateLeft(p);
            } else if(getBalance(p->right) == 1) {
                p->right = rotateRight(p->right);
                return rotateLeft(p);
            }
        }

        return p;
    }


    void insert(int key) {
        root = insert(root, key);
    }

    void preOrder(Node* node) {
        if (node) {
            cout << node->key << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void preOrderTraversal() {
        preOrder(root);
    }
        Node* findMinValueNode(Node* node) {
            Node* current = node;
            while (current->left != nullptr) {
                current = current->left;
            }
            return current;
        }

    Node* deleteNode(Node* root, int key) {
        if (!root) return root;

        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }

                delete temp;
            } else {
                Node* temp = findMinValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (root == nullptr) {
            return root;
        }

        root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

        int balance = getBalance(root);
        if (balance > 1) {
            if (getBalance(root->left) >= 0) {
                return rotateRight(root);
            } else {
                root->left = rotateLeft(root->left);
                return rotateRight(root);
            }
        }
        if (balance < -1) {
            if (getBalance(root->right) <= 0) {
                return rotateLeft(root);
            } else {
                root->right = rotateRight(root->right);
                return rotateLeft(root);
            }
        }

        return root;
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }
};

int main() {
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    cout << "Preorder traversal: "<<endl;
    avl.preOrderTraversal();
    cout<<endl;

    avl.deleteNode(50);

    cout << "Preorder traversal: "<<endl;
    avl.preOrderTraversal();
    cout<<endl;

    avl.deleteNode(10);

    cout << "Preorder traversal: "<<endl;
    avl.preOrderTraversal();
    cout<<endl;
    return 0;
}
