class Solution {
public:
    // 010 101
    // 字符串拼接 +　滑动窗口
    // 时间复杂度：O(n) 空间复杂度：O(n) n=s.size()
    int minFlips(string s) {
        string t1 = "0";
        for (int i = 1; i < s.size(); i++) {
            t1 += t1[i-1] == '0' ? '1' : '0';
        }
        string t2 = "1";
        for (int i = 1; i < s.size(); i++) {
            t2 += t2[i-1] == '0' ? '1' : '0';
        }
        if (s == t1 || s == t2) {
            return 0;
        }
        string T = s + s;
        // 滑动窗口
        int l = 0, r = s.size() - 1;
        auto calc = [&](string& k1, string& k2) {
            int ans = 0;
            for (int i = 0; i < k1.size(); i++) {
                if (k1[i] != k2[i]) {
                    ans++;
                }
            }
            return ans;
        };
        int num_t1, num_t2;
        num_t1 = calc(s, t1);
        num_t2 = calc(s, t2);
        int solve = INT_MAX;
        solve = min(solve, min(num_t1, num_t2));
        while (r < T.size()) {
            // 维护num_t1 num_t2
            num_t1 -= T[l] == t1[0] ? 0 : 1;
            num_t2 -= T[l] == t2[0] ? 0 : 1;
            l++;
            num_t1 = r - l + 1 - num_t1;
            num_t2 = r - l + 1 - num_t2;
            r++;
            num_t1 += T[r] == t1[t1.size() - 1] ? 0 : 1;
            num_t2 += T[r] == t2[t2.size() - 1] ? 0 : 1;
            solve = min(solve, min(num_t1, num_t2));
        }
        return solve;
    }
};
