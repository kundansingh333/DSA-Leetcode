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
        vector<vector<int>>ans;
        if(root==nullptr){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool isLeft=1;
        while(!q.empty()){
            // vector<int>temp;
            
            int lvlsize=q.size();
            vector<int>temp(lvlsize);
            int i=0;
            int originalsize=lvlsize;
            while(lvlsize--){
                TreeNode* f=q.front();
                q.pop();
                // temp.push_back(f->val);
                int index=isLeft?i:(originalsize-1-i);
                temp[index]=f->val;
                

                if(f->left!=nullptr){
                    q.push(f->left);

                }
                if(f->right!=nullptr){
                    q.push(f->right);
                }
                i++;
            }
            isLeft=1-isLeft;
            // if(isLeft){
            //     ans.push_back(temp);
            //     isLeft=1-isLeft;
            // }else{
            //     reverse(temp.begin(),temp.end());
            //     ans.push_back(temp);
            //     isLeft=1-isLeft;
            // }
            ans.push_back(temp);
        }
        return ans;
    }
};