typedef long long LL;
class Solution {
public:
	//利用dp进行
    int uniquePaths(int m, int n) {
		if (m <= 0 || n <= 0) return 0;
		if (m == 1 || n == 1) return 1;
		int base = m + n - 2, fac = min(m - 1, n - 1);
		vector<LL> dp(fac + 1, 0);
		//需要一个变量记录西北角
		int west_north, temp;
		for (int i = 0; i <= base; i++) {
			for (int j = 0; j <= fac; j++) {
				west_north = dp[j];
				if (i == 0 && j == 0) {
					dp[j] = 0;
					continue;
				}
				if (i == 0 || j == 0 || i <= j) {
					dp[j] = 1;
				} else {
					dp[j] = dp[j] + temp;
				}
				temp = west_north;
			}
		}
		return dp[fac];
    }
};
