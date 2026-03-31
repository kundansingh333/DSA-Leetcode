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
    vector<TreeNode*> sorted;
    void fun(TreeNode* root){
        if(root==nullptr){
            return;
        }
        fun(root->left);
        sorted.push_back(root);
        fun(root->right);
        return;
    }
    void recoverTree(TreeNode* root) {
        fun(root);
        int galat=0;
        TreeNode* galat1first=nullptr;
        TreeNode* galat1second=nullptr;

        TreeNode* galat2first=nullptr;
        TreeNode* galat2second=nullptr;
        for(int i=0; i<sorted.size()-1; i++){
            if(sorted[i]->val >=sorted[i+1]->val){
                if(galat==0){
                    galat1first=sorted[i];
                    galat1second=sorted[i+1];
                }
                galat++;
                galat2first=sorted[i];
                galat2second=sorted[i+1];
            }
        }
        if(galat==1){
            swap(galat1first->val,galat1second->val);
        }else{
            swap(galat1first->val,galat2second->val);
        }
    }
};