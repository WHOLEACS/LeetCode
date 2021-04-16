typedef pair<string, string> PII;
class Solution {
private:
    map<PII, bool> mp;
public:

    bool check(const string& s1, const string& s2) {
        vector<int> ans(26, 0);
        if (s1.size() != s2.size()) {
            return false;
        }
        int len = s1.size();
        for (int i = 0; i < len; i++) {
            ans[s1[i]-'a']++;
            ans[s2[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (ans[i]) {
                return false;
            }
        }
        return true;
    }
    // 记忆化搜索
    // 递归：返回值 调用单元 终止条件
    bool dfs(string s1, string s2) {
        if (s1 == s2) {
            return mp[make_pair(s1, s2)] = true;
        }
        PII now = make_pair(s1, s2);
        // 查询两个串是否出现字母类型或者字母数量不同的情况
        if(!check(s1, s2)) {
            return mp[now] = false;
        }
        if (mp.find(now) != mp.end()) {
            return mp[now];
        }
        // 枚举切割点
        int len = s1.size();
        for (int i = 0; i < len - 1; i++) {
            string ls1 = s1.substr(0, i + 1);
            string rs1 = s1.substr(i + 1, len - 1 - i);
            string ls2 = s2.substr(0, i + 1);
            string rs2 = s2.substr(i + 1, len - 1 - i);
            string ls2_n = s2.substr(0, len - 1 - i);
            string rs2_n = s2.substr(len - 1 - i, i + 1);
            if ((dfs(ls1, ls2) && dfs(rs1, rs2)) || (dfs(ls1, rs2_n) && dfs(rs1, ls2_n))) {
                return mp[now] = true;
            }
        }
        return mp[now] = false;
    }
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        return dfs(s1, s2);
    }
};
