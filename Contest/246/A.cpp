class Solution {
public:
    string largestOddNumber(string num) {
        int idx, len = num.size();
        idx = len;
        for (int i = 0; i < len; i++) {
            if ((num[i] - '0') & 1) {
                idx = i;
            }
        }
        if (idx == len) {
            return "";
        }
        return num.substr(0, idx + 1);
    }
};
