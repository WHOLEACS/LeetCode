typedef pair<int, int> PII;
class Solution {
public:
    // 哈希表 + 前缀表
    // 时间复杂度：O(n^2) 空间复杂度：O(n)
    int countTriplets(vector<int>& arr) {
        int len = arr.size();
        if (len < 2) {
            return 0;
        }
        vector<int> sum(len + 1, 0);
        for (int i = 1; i < len + 1; i++) {
            sum[i] = sum[i-1] ^ arr[i-1];
        }
        // 构造map
        map<PII, int> mp;
        mp.clear();
        // 枚举区间左值，填充map
        for (int i = 1; i < len; i++) {
            for (int j = i; j < len; j++) {
                mp[make_pair(i, sum[i] ^ sum[j+1])] += 1;
            }
        }
        // 枚举区间
        int solve = 0;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                int temp = sum[i] ^ sum[j];
                if (mp.find(make_pair(j, temp)) != mp.end()) {
                    solve += mp[make_pair(j, temp)];
                }
            }
        }
        return solve;
    }
};
