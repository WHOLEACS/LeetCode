class Solution {
public:
    // 双指针 时间复杂度：O(n) 空间复杂度：O(1)
    int characterReplacement(string s, int k) {
        int len = s.size();
        if (k >= len) {
            return len;
        }
        vector<int> temp(26, 0);
        int solve = k, last = 0;
        for (int i = 0; i <= len - k; i++) {
            // 寻找右边界
            int r = last, max_num = 1;
            while (r < len) {
                temp[s[r] - 'A'] += 1;
                max_num = 1;
                for (int j = 0; j < 26; j++) {
                    max_num = max(max_num, temp[j]);
                }
                if (r - i + 1 - max_num > k) {
                    break;
                }
                r++;
            }
            solve = max(solve, r - i);
            if (r >= len) {
                break;
            }
            temp[s[i]-'A'] -= 1;
            temp[s[r]-'A'] -= 1;
            last = r;
        }
        return solve;
    }
};
