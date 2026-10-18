class Solution {
public:
    int fun(int n){
        int count=0;
        while(n>0){
            n=n&(n-1);
            count++;
        }
        return count;
    }
    // struct Element{
    //     int val;
    //     int newVal;
    // };
    vector<int> sortByBits(vector<int>& arr) {
        // vector<Element> ans(arr.size());
        // for(int i=0; i<arr.size(); i++){
        //     ans[i]={arr[i],fun(arr[i])};
        // }
        // sort(ans.begin(),ans.end(),[](const Element&a,const Element&b){
        //     if(a.newVal==b.newVal){
        //         return a.val<b.val;
        //     }
        //     return a.newVal<b.newVal;
        // });
        // vector<int>arrr;
        // for(int i=0; i<arr.size(); i++){
        //     arrr.push_back(ans[i].val);
        // }
        sort(arr.begin(),arr.end(),[this](int a,int b){
            int countA=fun(a);
            int countB=fun(b);
            if(countA!=countB){
                return countA<countB;
            }
            return a<b;
        });
        return arr;
    }
};