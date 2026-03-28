/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans=nullptr;
    // int fun(TreeNode* root,TreeNode*p,TreeNode* q){
    //     if(root==nullptr){
    //         return 0;
    //     }
    //     int left=fun(root->left,p,q);
    //     int right=fun(root->right,p,q);
    //     int self=0;
    //     if(root == p || root==q){
    //         self=1;
    //     }
    //     int total=left+right+self;
    //     if(total==2 && ans==nullptr){
    //         ans=root;
    //         // return 
    //     }
    //     return total;
    // }

    void fun(TreeNode* root,int p, int q){
        if(root == nullptr){
            return;
        }
        if(root->val == p || root->val==q){
            ans=root;
            return;
        }else if(root->val < p){
            fun(root->right,p,q);
        }else if(root->val > q){
            fun(root->left,p,q);
        }else{
            ans=root;
            return;
        }
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int maxi=max(p->val,q->val);
        int mini=min(p->val,q->val);
        fun(root,mini,maxi);
        return ans;
    }
};