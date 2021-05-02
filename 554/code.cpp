class Solution {
public:
    // 哈希表
    int leastBricks(vector<vector<int>>& wall) {
        int len = wall.size();
        unordered_map<int, int> mp;
        mp.clear();
        int sum = 0;
        for (int i = 0; i < len; i++) {
            int ans = 0;
            for (int& k : wall[i]) {
                ans += k;
                mp[ans] += 1;
            }
            sum = ans;
        }
        int solve = -0x3f3f3f3f;
        for (auto& it : mp) {
            if (it.first == sum) {
                continue;
            }
            solve = max(solve, it.second);
        }
        return solve == -0x3f3f3f3f ? len : len - solve;
    }
};
