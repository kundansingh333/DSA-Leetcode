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
    pair<int, TreeNode*> getDeepest(TreeNode* root) {
        // Base Case: Empty node has depth 0
        if (root == NULL) return {0, NULL};

        // Step 1: Recursively ask children
        pair<int, TreeNode*> left = getDeepest(root->left);
        pair<int, TreeNode*> right = getDeepest(root->right);

        // Step 2: Compare Heights
        int leftHeight = left.first;
        int rightHeight = right.first;

        // Case A: Balanced -> Current Node is the LCA
        if (leftHeight == rightHeight) {
            return {leftHeight + 1, root};
        }
        
        // Case B: Left is deeper -> The answer is in the Left subtree
        else if (leftHeight > rightHeight) {
            return {leftHeight + 1, left.second};
        }
        
        // Case C: Right is deeper -> The answer is in the Right subtree
        else {
            return {rightHeight + 1, right.second};
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<int,TreeNode*>result=getDeepest(root);
        return result.second;
    }
};