#include <iostream>
#include <queue>

using namespace std;

struct Tree {
    int data;
    Tree* left;
    Tree* right;

    Tree(int value) : data(value), left(nullptr), right(nullptr) {}
};

Tree* buildTreeFromArray(const int arr[], int n, int index) {
    Tree* root = nullptr;

    if (index < n && arr[index] != -1) {
        root = new Tree(arr[index]);
        root->left = buildTreeFromArray(arr, n, 2 * index + 1);
        root->right = buildTreeFromArray(arr, n, 2 * index + 2);
    }

    return root;
}

bool areLeavesAtSameLevel(Tree* root) {
    if (root == nullptr) {
        return true;
    }
    queue<pair<Tree*, int>> q;
    q.push({root, 0});

    int leafLevel = -1;
    while (!q.empty()) {
        Tree* p = q.front().first;
        int level = q.front().second;
        q.pop();

        if (p->left == nullptr && p->right == nullptr) {
            if (leafLevel == -1) {
                leafLevel = level;
            } else if (leafLevel != level) {
                return false;
            }
        }
        if (p->left) q.push({p->left, level + 1});
        if (p->right) q.push({p->right, level + 1});
        
    }

    return true;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    Tree* root = buildTreeFromArray(arr, n, 0);
    cout<<endl;
    if (areLeavesAtSameLevel(root)) {
        cout << "All leaves are at the same level." << endl;
    } else {
        cout << "Leaves are not at the same level." << endl;
    }

    return 0;
}
