class Solution {
public:
    int bestClosingTime(string customers){
        int current_score=0;
        int max_score=0;
        int best_hour=0;

        for(int i=0; i<customers.length(); i++){
            if(customers[i]=='Y'){
                current_score++;
            }else{
                current_score--;
            }
            
            if(current_score>max_score){
                max_score=current_score;
                best_hour=i+1;
            }

        }
        return best_hour;
    }
};