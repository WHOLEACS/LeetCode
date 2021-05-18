typedef pair<int, int> PII;
class Solution {
public:
    // 哈希表 + 前缀表
    // 时间复杂度：O(n) 空间复杂度：O(n)
    int countTriplets(vector<int>& arr) {
        int len = arr.size();
        if (len < 2) {
            return 0;
        }
        vector<int> sum(len + 1, 0);
        for (int i = 1; i < len + 1; i++) {
            sum[i] = sum[i-1] ^ arr[i-1];
        }
        int solve = 0;
        unordered_map<int, PII> mp;
        mp.clear();
        mp[0] = make_pair(1, 0);
        // 枚举k的可能位置
        for (int i = 1; i < len; i++) {
            if (mp.find(sum[i+1]) != mp.end()) {
                solve += mp[sum[i+1]].first * i - mp[sum[i+1]].second;
            }
            mp[sum[i]].first += 1;
            mp[sum[i]].second += i;
        }
        return solve;
    }
};
