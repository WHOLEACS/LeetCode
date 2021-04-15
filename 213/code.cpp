class Solution {
public:
    // dp
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }
        vector<int> dp(len + 1, 0);
        // 由左向右
        // 首尾相连，两种方式，如果取第一个那么不能取最后一个；否则，如果不取第一个，可以取最后一个
        dp[1] = nums[0];
        for (int i = 2; i < len; i++) {
            dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
        }
        int solve = dp[len-1];
        for (int i = 0; i <= len; i++) {
            dp[i] = 0;
        }
        for (int i = 2; i <= len; i++) {
            dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
        }
        solve = max(solve, dp[len]);
        return solve;
    }
};
