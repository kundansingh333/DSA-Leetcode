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
    // vector<int>temp;
    // void inOrder(TreeNode* root){
    //     if(root==nullptr) return;
    //     inOrder(root->left);
    //     temp.push_back(root->val);
    //     inOrder(root->right);
    //     return;
    // }
    stack<TreeNode*>asc;
    stack<TreeNode*> desc;
    TreeNode* getSmall(){
        if(asc.empty()){
            return nullptr;
        }
        TreeNode* small=asc.top();
        asc.pop();
        TreeNode* rightChild=small->right;
        while(rightChild){
            asc.push(rightChild);
            rightChild=rightChild->left;
        }
        return small;
    }
    TreeNode* getBig(){
        if(desc.empty()){
            return nullptr;
        }
        TreeNode* big=desc.top();
        desc.pop();
        TreeNode* leftChild=big->left;
        while(leftChild){
            desc.push(leftChild);
            leftChild=leftChild->right;
        }
        return big;
    }
    bool findTarget(TreeNode* root, int k) {
        // inOrder(root);
        // int n=temp.size();
        // int left=0;
        // int right=n-1;
        
        // while(left<right){
        //     int sum=temp[left]+temp[right];
        //     if(sum==k){
        //         return true;
        //     }else if(sum<k){
        //         left++;
        //     }else{
        //         right--;
        //     }
            

        // }
        // return false;

        TreeNode* t=root;
        while(t){
            asc.push(t);
            t=t->left;
        }
        t=root;
        while(t){
            desc.push(t);
            t=t->right;
        }
        TreeNode* i=getSmall();
        TreeNode* j=getBig();
        while(i!=nullptr && j!=nullptr && i->val<j->val){
            int sum=i->val + j->val;
            if(sum==k){
                return true;
            }else if(sum<k){
                i=getSmall();
            }else{
                j=getBig();
            }
        }
        
        return false;
        
    }
};