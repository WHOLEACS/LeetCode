class Solution {
public:
    // 时间复杂度：O(n) 空间复杂度：O(n)
    // 定义3个指针，表明当前数*x的值正好大于当前的solve，那么下一个数必然从这些数中取最小得到，避免重复
    int nthUglyNumber(int n) {
        if (n == 1) {
            return 1;
        }
        vector<int> dp(n+1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; i++) {
            int solve = min(dp[p2]*2, min(dp[p3]*3, dp[p5]*5));
            dp[i] = solve;
            while (dp[p2] * 2 <= solve) {
                p2++;
            }
            while (dp[p3] * 3 <= solve) {
                p3++;
            }
            while (dp[p5] * 5 <= solve) {
                p5++;
            }
        }
        return dp.back();
    }
};
