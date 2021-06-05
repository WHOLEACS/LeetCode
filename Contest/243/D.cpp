const double eps = 1e-8;
class Solution {
public:
    // dp
    // 状态定义：f[i][j] 表示前i段跳过j次的最短耗时
    // 动态转移：以dist[i-1]是否要跳过讨论，跳过时，f[i][j]=f[i-1][j-1]+dist[i-1]/speed 否则，f[i][j]=f[i-1][j]+dist[i-1]/speed
    // 边界情况：f[i][j] 在j>i时不合法 f[0][0]=0 初始化f[i][j]=INF
    // return：dp[n][j] j列确定，选择dp[n][j] <= hoursBefore的最小的j次，如果没有，返回-1
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int len = dist.size();
        vector<vector<double>> dp(len+1, vector<double>(len+1));
        dp[0][0] = 0;
        for (int i = 1; i < len + 1; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    dp[i][j] = ceil(dp[i-1][j] + (double)dist[i-1]/speed - eps);
                    continue;
                }
                if (j == i) {
                    dp[i][j] = dp[i-1][j-1] + (double)dist[i-1]/speed;
                    continue;
                }
                dp[i][j] = min(ceil(dp[i-1][j] + (double)dist[i-1]/speed - eps), dp[i-1][j-1] + (double)dist[i-1]/speed);
            }
        }
        for (int i = 0; i <= len; i++) {
            if (dp[len][i] <= hoursBefore + eps) {
                return i;
            }
        }
        return -1;
    }
};
