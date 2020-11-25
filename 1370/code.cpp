class Solution {
private:
    int done[26];
public:
    Solution()
    {
        memset(done,0,sizeof(done));
    }
    //哈希表
    string sortString(string s) {
        int len = s.size();
        if (len <= 1) return s;
        string solve = "";
        int min_char = 26, max_char = 0;
        for (int i = 0; i < len; i++) {
            done[s[i]-'a']++;
            min_char = min(min_char, s[i]-'a');
            max_char = max(max_char, s[i]-'a');
        }
        int num = 0, last = min_char - 1;
        bool flag = true;
        while (num < len) {
            if (flag) {
                if (last < max_char) {
                    last++;
                    while (last < max_char && done[last] == 0) last++;
                } else {
                    flag = false;
                    while (last > min_char && done[last] == 0) last--;
                }
                if (last >= min_char && last <= max_char && done[last]) {
                    done[last]--;
                    solve += ('a' + last);
                    num++;
                }
            } else {
                if (last > min_char) {
                    last--;
                    while (last > min_char && done[last] == 0) last--;
                } else {
                    flag = true;
                    while (last < max_char && done[last] == 0) last++;
                }
                if (last >= min_char && last <= max_char && done[last]) {
                    done[last]--;
                    solve += ('a' + last);
                    num++;
                }
            }
        }
        return solve;
    }
};
