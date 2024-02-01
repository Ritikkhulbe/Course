#include <iostream>
#include <algorithm>

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

void printInorder(TreeNode* root) {
    if (root) {
        printInorder(root->left);
        cout << root->value << " ";
        printInorder(root->right);
    }
}
void printPostOrder(TreeNode* root) {
    if (root) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->value << " ";
    }
}

int main() {
    int inorderTraversal[] = {3, 4, 2, 1, 5, 8, 9};
    int levelOrderTraversal[] = {1, 4, 5, 9, 8, 2, 3};
    int size = sizeof(inorderTraversal) / sizeof(inorderTraversal[0]);

    TreeNode* root = buildTree(inorderTraversal, levelOrderTraversal, 0, size - 1, size);

    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);
    cout<<endl;
    cout << "Post-order Traversal of Constructed Tree: ";
    printPostOrder(root);
    return 0;
}
