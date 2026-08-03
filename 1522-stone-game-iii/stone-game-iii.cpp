class Solution {
public:
    
    int fun(vector<int>&piles,int i,int n,vector<int>&t){
        if(i>=n) return 0;
        int maxi=INT_MIN;
        int currentTakeSum=0;
        if(t[i]!=INT_MIN){
            return t[i];
        }
        for(int k=1; k<=3; k++){
            if(i+k-1<n){

                currentTakeSum+=piles[i+k-1];
                int currentScore=currentTakeSum-fun(piles,i+k,n,t);
                maxi=max(maxi,currentScore);
            }
        }
        return t[i]=maxi;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>t=vector<int>(n+1,INT_MIN);
        int val= fun(stoneValue,0,n,t);
        
        if(val>0){
            return "Alice";
        }else if(val==0){
            return "Tie";
        }
        else{
            return "Bob";
        }
    }
};