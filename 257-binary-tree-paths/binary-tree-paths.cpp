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
    void dfs(TreeNode* node, string currentPath, vector<string>& result) {
        if (!node) return;


        currentPath += to_string(node->val);


        if (!node->left && !node->right) {
            result.push_back(currentPath);
            return;
        }


        currentPath += "->";


        if (node->left) {
            dfs(node->left, currentPath, result);
        }
        if (node->right) {
            dfs(node->right, currentPath, result);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
};