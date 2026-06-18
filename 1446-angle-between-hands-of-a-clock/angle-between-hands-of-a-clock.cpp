class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour==12){
            hour=0;
        }

        double minutes_degree = minutes*6.0;
        double hours_degree = (hour*30.0)+(minutes*0.5);
        double angle=abs(minutes_degree-hours_degree);

        if(angle>180){
            return 360-angle;
        }
        return angle;

        
        
    }
};