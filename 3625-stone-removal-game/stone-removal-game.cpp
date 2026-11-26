class Solution {
public:
    bool canAliceWin(int n) {
        bool isAlice=0;
        int chance=10;
        while(n>=0){
            n-=chance;
            chance--;
        }
        if(chance%2==0 && chance>n){
            return true;
        }
        return false;
    }
};