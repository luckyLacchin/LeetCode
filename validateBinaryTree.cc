#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        else {
            if ((root -> left != NULL && root->left->val >= root->val) || (root -> right != NULL && root->right->val <= root->val)) {
                cout << "right: " << root->right->val << endl;
                cout << "left: " << root->left->val << endl;
                return false;
            }
            else {
                cout << "root: " << root->val << endl;              
                return true && isValidBST(root->left) && isValidBST(root->right);
            }
        }
    }
};



void testInvalidTree() {
    Solution solution;

    // Construct the tree [5,4,6,null,null,3,7]
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(3); // Invalid subtree
    root->right->right = new TreeNode(7);

    // Check if the tree is a valid BST
    bool result = solution.isValidBST(root);

    cout << "Test Case [5,4,6,null,null,3,7]: " << (result ? "Passed" : "Failed") << endl;
}

int main() {
    testInvalidTree();
    return 0;
}