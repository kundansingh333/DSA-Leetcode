class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char,int> romanMp;
        romanMp={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };

        // int l=s.length()-1;
        // int numbers=0;
        // for(int i=l; i>=0; i--){
            
            
        //     char curr_roman=s[i];
        //     int curr_number=romanMp[curr_roman];
        //     char next_roman=s[0];
        //     int next_number=romanMp[next_roman];
        //     int number=0;
        //     if(i>0){
        //         next_roman=s[i-1];
        //         next_number=romanMp[next_roman];
        //     }
            
            
            
        //     if(next_roman =='I' && (curr_roman=='V'|| curr_roman=='X')){
        //         number = curr_number-1;
        //     }
        //     if(next_roman=='X' && (curr_roman=='L'|| curr_roman=='C')){
        //         number = curr_number-10;
        //     }
        //     if(next_roman=='C' && (curr_roman=='D'|| curr_roman=='M')){
        //         number = curr_number-100;
        //     }
        //     number=romanMp[s[i]];
        //     numbers=numbers+number;
        //     // numbers+=1;
        // }
        // return numbers;

        int total=0;
        for(int i=0; i<s.length(); i++){
            int current_number=romanMp[s[i]];
            if(i+1 < s.length()){
                int next_number=romanMp[s[i+1]];
                if(current_number<next_number){
                    total+=next_number-current_number;
                    i++;
                }else{
                    total+=current_number;
                }
            }else{
                total+=current_number;
            }   
        }
        return total;
    }
};