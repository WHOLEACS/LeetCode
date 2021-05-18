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
        int solve = 0;
        for (int i = 0; i < len - 1; i++) {
            for (int k = i + 1; k < len; k++) {
                if (sum[i] == sum[k+1]) {
                    solve += k - i;
                }
            }
        }
        return solve;
    }
};
