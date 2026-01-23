class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        long long maxArea=LLONG_MIN;
        while(left<=right){
            int l=right-left;
            int b=min(height[left],height[right]);
            long long currentArea=(long long)l*b;
            maxArea=max(maxArea,currentArea);
            if(height[left]<=height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
};