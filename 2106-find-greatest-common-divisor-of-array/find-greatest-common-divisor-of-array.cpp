class Solution {
public:
    int gcdRecursive(int a,int b){
        if(b==0) return a;
        return gcdRecursive(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        int smallest=nums[0];
        int largest=nums[n-1];
        return gcdRecursive(smallest,largest);

    }
};