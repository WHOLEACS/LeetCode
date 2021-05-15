class Solution {
public:
    // 状压dp
    // 状态定义：dp[i][j]表示分配到i人时，工作状态为j，此时能够达到的最小化的最大工作时间
    // 状态转移：预处理sum数组表示所有的状态分配给一个人做的时候的情况，dp[i][j] = min(temp, max(dp[i-1][j的所有子集], sum[j的补集])) 维护temp，遍历j的所有子集状态，把temp赋值给dp[i][j]
    // 初始状态：dp[0][j] = sum[j]
    // 时间复杂度：O(n*(3^n)) 空间复杂度：O(n*(2^n))
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        int col = 1 << n;
        vector<vector<int>> dp(k, vector<int>(col));
        // 预处理sum数组
        vector<int> sum(col, 0);
        for (int i = 1; i < (1 << n); i++) {
            int x = __builtin_ctz(i), y = i - (1 << x);
            sum[i] = sum[y] + jobs[x];
        }
        // 初始状态
        for (int i = 0; i < (1 << n); i++) {
            dp[0][i] = sum[i];
        }
        for (int i = 1; i < k; i++) {
            for (int j = 0; j < (1 << n); j++) {
                int minn = INT_MAX;
                for (int x = j; x; x = (x - 1)&j) {
                    minn = min(minn, max(dp[i-1][x], sum[j-x]));
                }
                dp[i][j] = minn;
            }
        }
        return dp[k-1][(1<<n)-1];
    }
};
