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
    // vector<int> res;
    TreeNode* prev=nullptr;
    bool ans=true;

    void inOrder(TreeNode* root){
        // left-root-right
        if(root==nullptr){
            return ;
        }
        inOrder(root->left);
        // res.push_back(root->val);
        if(prev==nullptr){
            prev=root;
        }else{
            if(prev->val >=root->val){
                ans=false;
                prev=root;
                return;
            }
        }
        prev=root;
        inOrder(root->right);
        return;
    }
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        // for(int i=0; i<res.size()-1; i++){
        //     if(res[i]>=res[i+1]){
        //         return false;
        //     }
        // }
        // return true;
        return ans;

    }
};