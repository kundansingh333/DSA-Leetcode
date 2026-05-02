class Solution {
public:

    // bool checkPalindrome(string s){
    //     string s1=s;
    //     reverse(s1.begin(),s1.end());
    //     if(s==s1){
    //         return true; 
    //     }
    //     return false;
    // }

    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;

        }
        return true;
    }
    bool validPalindrome(string s) {
        // if(checkPalindrome(s)){
        //     return true;
        // }else{
        //     string s2=s;
        //     int left=0;
        //     int right=s.length()-1;
        //     while(left<right){
        //         if(s[left]!=s[right]){  
        //             s2.erase(left,1);
        //             if(checkPalindrome(s2)){
        //                 return true;
        //             }else{
        //                 s2.insert(left,1,s[left]);

        //             }
                    
        //             s2.erase(right,1);
        //             if(checkPalindrome(s2)){
        //                 return true;
        //             }else{
        //                 s2.insert(right,1,s[right]);
        //             }
        //             left++;
        //             right++;
        //         }
        //         left++;
        //         right--;
        //     }

        // }
        // return false;
        int left=0;
        int right=s.length()-1;

        while(left<right){
            if(s[left]!=s[right]){
                return isPalindrome(s,left+1,right) || isPalindrome(s,left,right-1);
            }
            left++;
            right--;
        }
        return true;
    }
};