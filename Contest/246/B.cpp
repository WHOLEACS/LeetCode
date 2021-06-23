class Solution {
private:
    int day = 24 * 60;
public:
    int numberOfRounds(string startTime, string finishTime) {
        int hour1 = (startTime[0] - '0') * 10 + (startTime[1] - '0') * 1;
        int min1 = (startTime[3] - '0') * 10 + (startTime[4] - '0') * 1;
        int hour2 = (finishTime[0] - '0') * 10 + (finishTime[1] - '0') * 1;
        int min2 = (finishTime[3] - '0') * 10 + (finishTime[4] - '0') * 1;
        int time_1 = hour1 * 60 + min1;
        int time_2 = hour2 * 60 + min2;
        if (time_2 < time_1) {
            time_2 += day;
        }
        int num1 = time_1 / 15;
        int num2 = time_2 / 15;
        int solve = num2 - num1 - (time_1 % 15 == 0 ? 0 : 1); 
        return solve > 0 ? solve : 0;
    }
};
