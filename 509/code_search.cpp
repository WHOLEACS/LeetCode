class Solution {
private:
	int dp[31];
public:
	Solution() {
		memset(dp, -1, sizeof(dp));
	}
	int calc(int n) {
		if (n <= 1) return dp[n] = n;
		if (dp[n] != -1) return dp[n];
		return dp[n] = calc(n-1) + calc(n-2);
	}
	// 1.循环 2.记忆化搜索
    int fib(int n) {
		if (n <= 1) return n;
		return calc(n);
    }
};
