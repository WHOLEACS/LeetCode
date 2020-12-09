const int maxn = 100 + 5;
typedef long long LL;
class Solution {
private:
	LL dp[maxn][maxn];
public:
	Solution() {
		memset(dp, -1, sizeof(dp));
	}
	//记忆化搜索
	//递归：返回值 调用单元 终止条件
	LL C(int base, int fac) {
		if (base == 0 && fac == 0) return dp[base][fac] = 0;
		if (base == 0 || fac == 0 || base <= fac) return dp[base][fac] = 1;
		if (dp[base][fac] != -1) return dp[base][fac];
		return dp[base][fac] = C(base - 1, fac) + C(base - 1, fac - 1);
	}
    int uniquePaths(int m, int n) {
		if (m <= 0 || n <= 0) return 0;
		if (m == 1 || n == 1) return 1;
		int base = m + n - 2, fac = min(m - 1, n - 1);
		return C(base, fac);
    }
};
