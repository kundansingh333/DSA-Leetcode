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
    void solve(TreeNode* root,vector<int> &ans){
        if(root==nullptr)return ;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0; i<n; i++){
                TreeNode* f=q.front();
                q.pop();
                if(i==n-1){
                    ans.push_back(f->val);
                }
                
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }


    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};