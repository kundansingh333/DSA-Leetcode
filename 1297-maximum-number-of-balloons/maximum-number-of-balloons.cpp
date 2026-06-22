class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>balloon{
            {'b',0},
            {'a',0},
            {'l',0},
            {'o',0},
            {'n',0}
        };
        for(auto ch:text){
            if(ch=='b'|| ch=='a' || ch=='l' || ch=='o' || ch=='n'){
                balloon[ch]++;
            }

        }
        balloon['l']/=2;
        balloon['o']/=2;
        int mini=INT_MAX;
        for(auto it:balloon){
            mini=min(it.second,mini);
        }
        return mini;
    }
};