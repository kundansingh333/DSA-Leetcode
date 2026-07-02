class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_map<int,int>nge_mp;
        stack<int>st;
        for(int i=n2-1; i>=0; i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                // ans[i]=-1;
                nge_mp[nums2[i]]=-1;
            }else{
                // ans[i]=st.top();
                nge_mp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }

        vector<int>ans(n1);
        for(int i=0; i<n1; i++){
            ans[i]=nge_mp[nums1[i]];
        }

        
        return ans;
    }
};