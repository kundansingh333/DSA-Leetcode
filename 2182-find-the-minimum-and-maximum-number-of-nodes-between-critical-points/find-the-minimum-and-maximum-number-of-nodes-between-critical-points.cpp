/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>index;
        int idx=2;
        ListNode* current=head->next;
        ListNode* prev=head;
        while(current->next!=nullptr){
            if(current->val> prev->val && current->val>current->next->val){
                index.push_back(idx);
            }else if(current->val < prev->val && current->val < current->next->val){
                index.push_back(idx);
            }
            prev=current;
            current=current->next;

            idx++;
        }
        int n=index.size();
        if(n<2) return {-1,-1};
        int mini=INT_MAX;
        for(int i=1; i<n; i++){
            mini=min(mini,index[i]-index[i-1]);
        }
        int maxi=index.back()-index.front();
        return {mini,maxi};

    }
};