class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int>q;
        vector<bool>visited(n,false);
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            if(arr[curr]==0){
                return true;
            }
            int left=curr-arr[curr];
            int right=curr+arr[curr];

            if(left>=0 && !visited[left]){
                visited[left]=true;
                q.push(left);
            }
            if(right<n && !visited[right]){
                visited[right]=true;
                q.push(right);
            }

        }
        return false;
        
    }
};