class Solution {
public:
    // 双指针 + 滑动窗口
    // 时间复杂度：O(n) 空间复杂度：O(1)
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.size();
        int temp = 0, last = 0, solve = 0;
        for (int i = 0; i < len; i++) {
            int r = last;
            while (r < len) {
                if (s[r] != t[r]) {
                    temp += abs(s[r] - t[r]);
                }
                if (temp > maxCost) {
                    break;
                }
                r++;
            }
            solve = max(solve, r - i);
            if (r >= len) {
                break;
            }
            if (s[r] != t[r]) {
                temp -= abs(s[r] - t[r]);
            }
            if (s[i] != t[i]) {
                temp -= abs(s[i] - t[i]);
            }
            last = r;
        }
        return solve;
    }
};
