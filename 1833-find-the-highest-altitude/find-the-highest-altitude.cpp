class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size()+1;
        vector<int> altitudes(n+1);
        altitudes[0]=0;
        for(int i=1; i<n; i++){
            altitudes[i]=altitudes[i-1]+gain[i-1];
        }
        int maxi=*max_element(altitudes.begin(),altitudes.end());
        return maxi;
    }
};