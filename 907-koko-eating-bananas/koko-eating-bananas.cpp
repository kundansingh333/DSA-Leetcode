class Solution {
public:
    long long speed(vector<int>&piles,int n,int speed){
        long long hour=0;
        for(int i=0; i<n; i++){
            int pileHour=piles[i]/speed;
            if(piles[i]%speed!=0){
                pileHour++;
            }
            hour+=pileHour;
        }
        return hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int n=piles.size();
        int maxi=INT_MIN;
        int res=-1;

        for(int i=0; i<n;i++){
            maxi=max(maxi,piles[i]);
        }

        int high=maxi;

        while(low<=high){
            int mid=low+(high-low)/2;
            long long hour=speed(piles,n,mid);
            if(hour>h){
                low=mid+1;
            }else{
                res=mid;
                high=mid-1;
            }
        }
        return res;
        
        
    }
};