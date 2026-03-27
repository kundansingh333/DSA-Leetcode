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
    bool fun(TreeNode* r1,TreeNode* r2){
        if(r1==nullptr && r2==nullptr){
            return true;
        }
        if(r1==nullptr || r2==nullptr){
            return false;
        }
        if(r1->val != r2->val){
            return false;
        }
        bool c1=fun(r1->left,r2->right);
        bool c2=fun(r1->right,r2->left);

        return (c1 && c2);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        return fun(root->left,root->right);
     
        
    }
};