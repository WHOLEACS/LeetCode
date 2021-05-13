const int MOD = 1e9 + 7;
class Solution {
public:
    // 动态规划
    // 状态定义：dp[i][j] 表示经过i步后提留在j处的方案数
    // 状态转移：dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]
    // 边界情况
    int numWays(int steps, int arrLen) {
        int dp[505][505];
        dp[0][0] = 1;
        int col = min(steps, arrLen);
        for (int i = 1; i < col; i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j < col; j++) {
                dp[i][j] = (((j-1 >= 0 ? dp[i-1][j-1] : 0) + dp[i-1][j])%MOD + (j+1 < col ? dp[i-1][j+1] : 0))%MOD;
            }
        }
        return dp[steps][0] % MOD;
    }
};
