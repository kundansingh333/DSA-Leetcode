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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==nullptr) return ans;
        bool left_to_right=true;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>sol(n);
            for(int i=0; i<n; i++){
                TreeNode* f=q.front();
                q.pop();
                int index=left_to_right?i:(n-1-i);
                sol[index]=f->val;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);

            }
            left_to_right=!left_to_right;
            ans.push_back(sol);
        }
        
        return ans;
    }
    
};