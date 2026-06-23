class Solution {
public:
    string convertToBinary(int signed_num){
        unsigned int num = signed_num;
        if(num==0){
            return "0000";
        }
        string ans="";
        while(num>0){
            ans+=to_string(num%2);
            num=num/2;
        }
        reverse(ans.begin(),ans.end());

        //padding logic
        int remainder=ans.length()%4;
        if(remainder!=0){
            int zeros_to_add=4-remainder;
            ans=string(zeros_to_add,'0')+ans;
        }
        return ans;
    }
    
    string toHex(int num) {
        string binary=convertToBinary(num);
        unordered_map<string,char> hashMap{
            {"0000",'0'},{"0001",'1'},{"0010",'2'},{"0011",'3'},{"0100",'4'},
            {"0101",'5'},{"0110",'6'},{"0111",'7'},{"1000",'8'},{"1001",'9'},
            {"1010",'a'},{"1011",'b'},{"1100",'c'},{"1101",'d'},{"1110",'e'},
            {"1111",'f'}
        };
        string hexResult="";
        for(int i=0; i<binary.length(); i+=4){
            string chunk=binary.substr(i,4);
            hexResult+=hashMap[chunk];
        }
        return hexResult;
    }
};