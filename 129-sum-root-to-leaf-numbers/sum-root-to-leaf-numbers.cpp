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
    int totalSum=0;
    void fun(TreeNode* root,int sum,int unit){
        if(root==nullptr) return;
        sum=(sum*unit)+root->val;
        // unit=unit*10;
        if(root->left == nullptr && root->right==nullptr){
            totalSum+=sum;
            return;
        }
        fun(root->left,sum,unit);
        fun(root->right,sum,unit);
        return; 
    }
    int sumNumbers(TreeNode* root) {
        fun(root,0,10);
        return totalSum;
    }
};