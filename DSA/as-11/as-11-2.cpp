#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(int inorder[], int levelOrder[], int inStart, int inEnd, int levelSize) {
    if (inStart > inEnd || levelSize <= 0) {
        return nullptr;
    }

    int rootValue = levelOrder[0];
    TreeNode* root = new TreeNode(rootValue);

    int rootIndex = find(inorder + inStart, inorder + inEnd + 1, rootValue) - inorder;

    int leftInSize = rootIndex - inStart;
    int rightInSize = inEnd - rootIndex;

    int* levelOrderLeft = new int[leftInSize];
    int* levelOrderRight = new int[rightInSize];

    int leftIndex = 0, rightIndex = 0;

    for (int i = 1; i < levelSize; ++i) {
        if (find(inorder, inorder + rootIndex, levelOrder[i]) != inorder + rootIndex) {
            levelOrderLeft[leftIndex++] = levelOrder[i];
        } else {
            levelOrderRight[rightIndex++] = levelOrder[i];
        }
    }

    root->left = buildTree(inorder, levelOrderLeft, inStart, rootIndex - 1, leftInSize);
    root->right = buildTree(inorder, levelOrderRight, rootIndex + 1, inEnd, rightInSize);

    delete[] levelOrderLeft;
    delete[] levelOrderRight;

    return root;
}

void inorderTraversal(TreeNode* root) {
    if (!root) {
        return;
    }

    stack<TreeNode*> nodeStack;

    while (root != nullptr || !nodeStack.empty()) {
        while (root != nullptr) {
            nodeStack.push(root);
            root = root->left;
        }
        root = nodeStack.top();
        nodeStack.pop();
        cout << root->value << " ";
        root = root->right;
    }
}

int main() {
    int inorder[] = {3, 4, 2, 1, 5, 8, 9};
    int levelOrder[] = {1, 4, 5, 9, 8, 2, 3};
    int size = sizeof(inorder) / sizeof(inorder[0]);

    TreeNode* root = buildTree(inorder, levelOrder, 0, size - 1, size);

    cout << "\n\nInorder Traversal of Constructed Tree without Recursion: ";
    inorderTraversal(root);
    cout<<"\n\n\n";
    return 0;
}
