class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // int maxi=0;
        // for(int i=0; i<arr1.size(); i++){
        //     string s1=to_string(arr1[i]);
        //     int len_s1=s1.length();
        //     for(int j=0; j<arr2.size();j++){
        //         string s2=to_string(arr2[j]);
        //         int len_s2=s2.length();
        //         int l1=0;
        //         int l2=0;
        //         int count=0;
        //         while(l1<len_s1 && l2<len_s2){
        //             if(s1[l1]==s2[l2]){
        //                 count++;
        //             }else{
        //                 break;
        //             }
        //             l1++;
        //             l2++;
        //         }
        //         maxi=max(maxi,count);
        //     }
        // }
        // return maxi;

        int maxi=0;
        unordered_set<string> s;

        // 1.storing the prefix in set
        for(int i=0; i<arr1.size(); i++){
            string s1=to_string(arr1[i]);
            string current="";
            for(auto ch:s1){
                current+=ch;
                s.insert(current);
            }
        }
        //2.matching the prefixes from set to arr2
        for(int i=0; i<arr2.size(); i++){
            string s1=to_string(arr2[i]);
            string current="";
            int maxLen=0;
            for(auto ch:s1){
                current+=ch;
                if(s.count(current)){
                    maxLen++;
                }else{
                    break;
                }
            }
            maxi=max(maxi,maxLen);
        }
        return maxi;
    }
};