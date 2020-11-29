class Solution {
public:
	//动态规划
	//1.问题定义 2.状态转移 3.边界情况
	//时间复杂度：O(len_1*len_2) 空间复杂度：O(len_2)
	//使用滚动数组优化空间复杂度 我们发现每次状态转移只和前一行的状态相关
    bool isInterleave(string s1, string s2, string s3) {
		int len_1 = s1.size(), len_2 = s2.size(), len_3 = s3.size();
		if (len_1 + len_2 != len_3) return false;
		vector<bool> dp(len_2 + 1, false);
		dp[0] = true;
		for (int i = 0; i <= len_1; i++)
		{
			for (int j = 0; j <= len_2; j++)
			{
				if (i == 0 && j == 0) continue;
				if (i == 0 && j) {
					dp[j] = dp[j-1] && s2[j - 1] == s3[i + j - 1];
				}
				else if (j == 0 && i) {
					dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
				}
				else {
					dp[j] = (dp[j] && s1[i-1] == s3[i+j-1]) || (dp[j-1] && s2[j-1] == s3[i+j-1]);
				}
			}
		}
		return dp[len_2];
    }
};
