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
    vector<int>temp;
    void inOrder(TreeNode* root){
        if(root==nullptr) return;
        inOrder(root->left);
        temp.push_back(root->val);
        inOrder(root->right);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        inOrder(root);
        int n=temp.size();
        int left=0;
        int right=n-1;
        
        while(left<right){
            int sum=temp[left]+temp[right];
            if(sum==k){
                return true;
            }else if(sum<k){
                left++;
            }else{
                right--;
            }
            

        }
        return false;
    }
};