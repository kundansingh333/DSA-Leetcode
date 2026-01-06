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
int levelOrder(TreeNode* root){
    queue <TreeNode* > q;
    q.push(root);
    
    // Treenode=q.front();
    int max_sum=INT_MIN;
    int max_level=0;
    int current_level=0;


    while(!q.empty()){
        int size=q.size();
        current_level++;
        int current_sum=0;

        for(int i=0; i<size; i++){
            TreeNode* current=q.front();
            q.pop();
            current_sum+=current->val;
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
        
        if(current_sum>max_sum){
            max_sum=current_sum;
            max_level=current_level;
        }
        
        
    }
    return max_level;
}
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int level=levelOrder(root);
        return level;
    }
};