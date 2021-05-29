class Solution {
public:
    // 每次操作左边的石子数量不变
    // 一个石子时，结束游戏
    int stoneGameVIII(vector<int>& stones) {
        // 前缀和
        int len = stones.size();
        vector<int> dp(len, 0);
        vector<int> pre(len, 0);
        pre[0] = stones[0];
        for (int i = 1; i < len; i++) {
            pre[i] = pre[i-1] + stones[i];
        }
        dp[len - 1] = pre[len - 1];
        for (int i = len - 2; i >= 1; i--) {
            dp[i] = max(dp[i+1], pre[i] - dp[i+1]);
        }
        return dp[1];
    }
};
