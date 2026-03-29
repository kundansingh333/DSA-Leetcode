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
    bool ans=false;
    void fun(TreeNode* root,int target, int sum){
        if(root==nullptr){
            return;
        }
        sum+=root->val;
        if(root->left==nullptr && root->right==nullptr){
            if(sum==target){
                ans=true;
                return;
            }
        }
        fun(root->left,target,sum);
        fun(root->right,target,sum);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        fun(root,targetSum,0);
        return ans;
    }
};