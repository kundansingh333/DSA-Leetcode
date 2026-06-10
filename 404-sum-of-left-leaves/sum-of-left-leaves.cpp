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
    
    int sumOfLeftLeaves(TreeNode* root) {
        
        if (root == nullptr) {
            return 0;
        }

        int sum = 0;

        // Check if the left child exists and is a leaf node
        if (root->left != nullptr) {
            if (root->left->left == nullptr && root->left->right == nullptr) {
                // Found a left leaf! Add its value
                sum += root->left->val;
            } else {
                // If it's a left child but not a leaf, explore deeper into it
                sum += sumOfLeftLeaves(root->left);
            }
        }

        // Always explore the right subtree for more left leaves
        if (root->right != nullptr) {
            sum += sumOfLeftLeaves(root->right);
        }

        return sum;
        
    }
};