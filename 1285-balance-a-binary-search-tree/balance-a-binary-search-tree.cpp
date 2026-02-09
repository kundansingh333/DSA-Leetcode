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
    vector<int>sortedVals;
    void inOrderTraversal(TreeNode* root){
        if(root==nullptr) return;
        inOrderTraversal(root->left);
        sortedVals.push_back(root->val);
        inOrderTraversal(root->right);
    }
    TreeNode* buildBalancedBST(int start,int end){
        if(start>end){
            return nullptr;
        }
        int mid=start+(end-start)/2;
        TreeNode* node=new TreeNode(sortedVals[mid]);
        node->left=buildBalancedBST(start,mid-1);
        node->right=buildBalancedBST(mid+1,end);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        sortedVals.clear();
        inOrderTraversal(root);
        return buildBalancedBST(0,sortedVals.size()-1);
    }
};