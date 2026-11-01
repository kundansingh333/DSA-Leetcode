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
    int totalTilt = 0;
    int calculateSum(TreeNode* node) {
        if (!node) return 0;

        int leftSum = calculateSum(node->left);
        int rightSum = calculateSum(node->right);

        totalTilt += std::abs(leftSum - rightSum);

        return node->val + leftSum + rightSum;
    }
    int findTilt(TreeNode* root) {
        calculateSum(root);
        return totalTilt;
    }
};