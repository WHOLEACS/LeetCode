class Solution {
private:
    using LL = long long;
    static constexpr int MOD = 1e9 + 7;
public:
    // 要求总浪费空间最小化
    // 由箱子进行二分，提示sum(boxes[j].length) <= 10^5
    // 前缀和 + 二分 + 双指针 取模放到最后进行
    // 时间复杂度：O(mlogm+m+n(klogk+klogm)) 空间复杂度：O(m+n) m:packages.size() n:boxes.size() k:boxes[i].size()
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        sort(packages.begin(), packages.end());
        int len_box = boxes.size(), len_pac = packages.size();
        LL solve = LLONG_MAX;
        vector<LL> sum(len_pac + 1, 0);
        for (int i = 1; i < len_pac + 1; i++) {
            sum[i] = 1l * sum[i-1] + 1l * packages[i-1];
        }
        for (int i = 0; i < len_box; i++) {
            vector<int> temp = boxes[i]; 
            sort(temp.begin(), temp.end());
            if (temp[temp.size() - 1] < packages[len_pac - 1]) {
                continue;
            }
            LL k = 0;
            int l = 0, r;
            for (int& it : temp) {
                r = upper_bound(packages.begin(), packages.end(), it) - packages.begin();
                if (r <= l) {
                    continue;
                }
                k = (k + (1l * (1l * r - l) * it - 1l * sum[r] + sum[l]));
                l = r;
                if (l == packages.size()) {
                    break;
                }
            }
            solve = min(solve, k);
        }
        return solve == LLONG_MAX ? -1 : solve % MOD;
    }
};
