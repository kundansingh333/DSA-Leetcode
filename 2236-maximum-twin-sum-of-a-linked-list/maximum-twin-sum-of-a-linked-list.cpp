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
        // int sum=0;
        // ListNode* temp=head;
        // vector<int>arr;
        // while(temp!=nullptr){
        //     arr.push_back(temp->val);
        //     temp=temp->next;
        // }
        // int i=0;
        // int j=arr.size()-1;
        // int maxi=0;
        // while(i<j){
        //     int sum=arr[i]+arr[j];
        //     maxi=max(maxi,sum);
        //     // return sum;
        //     i++;
        //     j--;

        // }
        // return maxi;


        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;

        }

        ListNode* prev=nullptr;
        ListNode* curr=slow;
        while(curr!=nullptr){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        ListNode* firstHalf=head;
        ListNode* secondHalf=prev;
        int maxSum=0;
        while(secondHalf!=nullptr){
            int curr_sum=firstHalf->val+secondHalf->val;
            maxSum=max(maxSum,curr_sum);
            secondHalf=secondHalf->next;
            firstHalf=firstHalf->next;
        }
        return maxSum;

        
    }
};