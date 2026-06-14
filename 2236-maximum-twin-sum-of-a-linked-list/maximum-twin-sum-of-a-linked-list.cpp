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
    int pairSum(ListNode* head) {
        int sum=0;
        ListNode* temp=head;
        vector<int>arr;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int i=0;
        int j=arr.size()-1;
        int maxi=0;
        while(i<j){
            int sum=arr[i]+arr[j];
            maxi=max(maxi,sum);
            // return sum;
            i++;
            j--;

        }
        return maxi;
        
    }
};