class Solution {
public:
    int dayOfYear(string date) {
        int year  = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(5, 2));
        int day   = std::stoi(date.substr(8, 2));

       
        const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        int totalDays = day;
        for (int i = 0; i < month - 1; ++i) {
            totalDays += daysInMonth[i];
        }

    
        if (isLeap && month > 2) {
            totalDays += 1;
        }

        return totalDays;
    }
};