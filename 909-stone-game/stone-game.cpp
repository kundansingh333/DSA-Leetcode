class Solution {
public:
    vector<vector<int>>t=vector<vector<int>>(501,vector<int>(501,-1));
    int fun(vector<int>&piles,int left,int right){
        if(left==right) return piles[left];


        if(t[left][right]!=-1) return t[left][right];
        int leftPart=piles[left]-fun(piles,left+1,right);
        int rightPart=piles[right]-fun(piles,left,right-1);
        return t[left][right]=max(leftPart,rightPart);
    }
    bool stoneGame(vector<int>& piles) {
        return fun(piles,0,piles.size()-1)>=0;
    }
};