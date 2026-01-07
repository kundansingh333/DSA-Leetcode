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
    vector<long long> store;
    long long totalSum(TreeNode* root){
        if(root==NULL) return 0;
        long long l_sum=totalSum(root->left);
        long long r_sum=totalSum(root->right);
        int current_sum=root->val+l_sum+r_sum;
        store.push_back(current_sum);
        return current_sum;
    }
    int maxProduct(TreeNode* root) {
        long long maxi=INT_MIN;
        long long S=totalSum(root);
        for(auto i:store){
            long long current_p=i*(S-i);
            if(current_p>maxi){
                maxi=current_p;
            }
        }
        return maxi%1000000007;
    }
    
};