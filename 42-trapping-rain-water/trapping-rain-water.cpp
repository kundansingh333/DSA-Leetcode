class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftMax(n,0);
        vector<int> rightMax(n,0);


        int maxiLeft=height[0];
        leftMax[0]=maxiLeft;


        for(int i=1; i<height.size(); i++){
            maxiLeft=max(maxiLeft,height[i]);
            leftMax[i]=maxiLeft;
        }


        int maxiRight=height[height.size()-1];
        rightMax[n-1]=maxiRight;
        for(int i=height.size()-2; i>=0; i--){
            maxiRight=max(maxiRight,height[i]);
            rightMax[i] = maxiRight;
        }
        int count=0;
        for(int i=0; i<height.size(); i++){
            count+=max(0,min(leftMax[i],rightMax[i]))-height[i];
        }
        return count;
    }
};