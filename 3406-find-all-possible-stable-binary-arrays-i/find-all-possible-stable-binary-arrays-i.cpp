class Solution {
public:
    int M=1e9+7;
    int t[201][201][2];
    int solve(int zeroLeft,int oneLeft,bool lastWasOne,int limit){
        if(zeroLeft==0 && oneLeft==0){
            return 1;
        }

        if(t[zeroLeft][oneLeft][lastWasOne]!=-1){
            return t[zeroLeft][oneLeft][lastWasOne];
        }

        int result=0;
        if(lastWasOne==true){
            //explore 0's
            for(int len=1; len<=min(limit,zeroLeft); len++){
                result=(result+solve(zeroLeft-len,oneLeft,false,limit))%M;
            }

        }else{
            //explore 1's
            for(int len=1; len<=min(limit,oneLeft); len++){
                result=(result+solve(zeroLeft,oneLeft - len,true,limit))%M;
            }
        }
        return t[zeroLeft][oneLeft][lastWasOne]=result;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t,-1,sizeof(t));
        int startWithZero=solve(zero,one,true,limit);
        int startWithOne=solve(zero,one,false,limit);
        return (startWithZero+startWithOne)%M;
    }
};