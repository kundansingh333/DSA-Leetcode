class Solution {
public:
    int dateToDays(string date){
        int daysInMonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        int days=(date[3]-'0')*10+(date[4]-'0');
        int month=(date[0]-'0')*10+(date[1]-'0');
        int totalDays=0;
        for(int i=1; i<month; i++){
            totalDays+=daysInMonth[i];
        }
        return totalDays+days;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        int arriveA=dateToDays(arriveAlice);
        int arriveB=dateToDays(arriveBob);
        int leaveA=dateToDays(leaveAlice);
        int leaveB=dateToDays(leaveBob);

        int startOverlap=max(arriveA,arriveB);
        int endOverlap=min(leaveA,leaveB);
        return max(0,endOverlap-startOverlap+1);
    }
};