class Solution {
public:
    int fun(int n){
        int sum=0;
        while(n>0){
            int rem=n%10;
            sum+=rem;
            n/=10;
        }
        return sum;
    }
    struct Element{
        int val;
        int digitSum;
        int originalIndex;
    };
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<Element>arr(n);

        for(int i=0; i<n; i++){
            arr[i]={nums[i],fun(nums[i]),i};
        }

        sort(arr.begin(),arr.end(),[](const Element&a,const Element&b){
            if(a.digitSum!=b.digitSum){
                return a.digitSum<b.digitSum;
            }
            return a.val<b.val;
        });
        
        vector<bool> visited(n,false);
        int swaps=0;
        for(int i=0; i<n; i++){
            if(visited[i] || arr[i].originalIndex==i){
                continue;
            }
            int cycleSize=0;
            int curr=i;

            while(!visited[curr]){
                visited[curr]=true;
                curr=arr[curr].originalIndex;
                cycleSize++;
            }
            if(cycleSize>1){
                swaps+=(cycleSize-1);
            }

        }
        return swaps;

    }
};