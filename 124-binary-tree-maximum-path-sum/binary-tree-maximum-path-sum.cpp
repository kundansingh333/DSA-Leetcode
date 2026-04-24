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

    int solve(TreeNode* root,int &res){
        //base case
        if(root==nullptr){
            return 0;
        }
        

        //hypothesis
        // int left=max(0,solve(root->left,res));
        // int right=max(0,solve(root->right,res));


        int left=solve(root->left,res);
        int right=solve(root->right,res);

        //induction step
        // int temp=max(left,right)+root->val;
        // int ans=left+right+root->val;
        // res=max(res,ans);
        // return temp;

        int temp=max(max(left,right)+root->val,root->val);
        int ans=max(temp,left+right+root->val);
        res=max(res,ans);
        return temp;

    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        solve(root,res);
        return res;                
    }
};