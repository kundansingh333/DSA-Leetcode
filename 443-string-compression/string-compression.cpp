class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int ans=0;
        int n=chars.size();

        while(i<n){
            int j=i+1;
            while(j<n && chars[j]==chars[i]){
                j++;
            }
            chars[ans++]=chars[i];
            int count = j-i;
            if(count>1){
                string countStr=to_string(count);
                for(auto it:countStr){
                    chars[ans++]=it;
                }
            }
            i=j;

        }
        return ans;

    }
};