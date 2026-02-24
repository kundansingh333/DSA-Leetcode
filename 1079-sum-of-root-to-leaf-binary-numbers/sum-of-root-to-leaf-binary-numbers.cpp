/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int total = 0;
    
    void preOrder(TreeNode* root, int currentSum) {
        if (root == nullptr) {
            return;
        }
        currentSum = (currentSum * 2) + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            total += currentSum;
            return;
        }
        preOrder(root->left, currentSum);
        preOrder(root->right, currentSum);
    }
    int sumRootToLeaf(TreeNode* root) {
        preOrder(root, 0);
        return total;
    }
};