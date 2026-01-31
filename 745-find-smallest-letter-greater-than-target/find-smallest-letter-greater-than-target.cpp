class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // for(int i=0; i<letters.size(); i++){
        //     if(letters[i]>target){
        //         return letters[i];
        //     }
        // }
        // return letters[0];
        int low=0;
        int high=letters.size()-1;
        char res=letters[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(letters[mid]<=target){
                low=mid+1;
            }else{
                res=letters[mid];
                high=mid-1;
            }
        }
        return res;

    }
};