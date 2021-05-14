const string level[] = {"I", "X", "C", "M"};
const string five[] = {"V", "L", "D"};
const string ten[] = {"X", "C", "M"};
class Solution {
public:
    // 字符串处理 时间复杂度：O(n) 空间复杂度：O(n)
    string create(const char& target, const int& idx, const int& len) {
        int level_idx = len - 1 - idx;
        string ans = "";
        if (target <= '5') {
            if (target == '4') {
                return level[level_idx] + five[level_idx];
            } else {
                if (target == '5') {
                    return five[level_idx];
                } else {
                    for (int i = 0; i < target - '0'; i++) {
                        ans += level[level_idx];
                    }
                }
            }
        } else {
            if (target == '9') {
                return level[level_idx] + ten[level_idx];
            } else {
                ans = five[level_idx];
                for (int i = 0; i < target - '5'; i++) {
                    ans += level[level_idx];
                }
            }
        }
        return ans;
    }

    string intToRoman(int num) {
        string ans = to_string(num);
        int len = ans.size();
        string solve = "";
        for (int i = 0; i < len; i++) {
            if (ans[i] == '0') {
                continue;
            }
            solve += create(ans[i], i, len);
        }
        return solve;
    }
};
