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
    vector<vector<int>>ans;
    
    // int count =0;
    void fun(TreeNode* root , int target, int sum ,vector<int> &diary){
        if(root==nullptr) return;
        sum+=root->val;
        diary.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(sum==target){
                ans.push_back(diary);
                diary.pop_back();
                // count++;
                return;
            }
        }
        fun(root->left,target,sum,diary);
        fun(root->right,target,sum,diary);
        diary.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> diary;
        fun(root,targetSum,0,diary);
        return ans;
    }
};