class Solution {
public:
    int minimumDeletions(string s) {
        int b_count=0;
        int min_deletion=0;
        for(auto it:s){
            if(it=='b'){
                b_count++;
            }else{
                min_deletion=min(min_deletion+1,b_count);
            }
        }
        return min_deletion;

    }
};