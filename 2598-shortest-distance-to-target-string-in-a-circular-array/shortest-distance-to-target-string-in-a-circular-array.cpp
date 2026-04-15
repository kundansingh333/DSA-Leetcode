class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int mini=n;
        for(int i=0; i<n; i++){
            if(words[i]==target){
                int straight=abs(startIndex-i);
                int circular=n-straight;
                int current=min(straight,circular);
                mini =min(mini,current);
            }
        }
        return mini==n?-1:mini;
    }
};