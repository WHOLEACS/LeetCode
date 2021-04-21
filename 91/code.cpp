class Solution {
public:
    int toint(const string& target)  {
        return (target[0] - '0') * 10 + (target[1] - '0');
    }

    int numDecodings(string s) {
        int len = s.size();
        if (s[0] == '0') {
            return 0;
        }
        vector<int> dp(len, 0);
        dp[0] = 1;
        for (int i = 1; i < len; i++) {
            string temp = s.substr(i - 1, 2);
            int num = toint(temp);
            if (s[i] == '0') {
                if (num == 10 || num == 20) {
                    dp[i] = i - 2 >= 0 ? dp[i-2] : 1;
                } else {
                    return 0;
                }
            } else {
                if (num >= 11 && num <= 26) {
                    dp[i] = dp[i-1] + (i-2>=0 ? dp[i-2] : 1);
                } else {
                    dp[i] = dp[i-1];
                }
            }
        }
        return dp[len-1];
    }
};
