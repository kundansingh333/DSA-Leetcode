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
    vector<vector<int>> fun(TreeNode* root,vector<vector<int>>&ans){
        if(root==nullptr) return {};
        queue<TreeNode*>q;
        q.push(root);
        bool l_to_r=true;
        while(!q.empty()){
            int n=q.size();
            vector<int>sol(n);
            for(int i=0; i<n; i++){
                TreeNode* f=q.front();
                q.pop();
                int index=l_to_r?i:(n-1-i);
                sol[index]=f->val;
                if(f->left) q.push(f->left);
                if(f->right)q.push(f->right);
            }
            l_to_r=!l_to_r;
            ans.push_back(sol);
        }
        return ans;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        return fun(root,ans);

    }
};