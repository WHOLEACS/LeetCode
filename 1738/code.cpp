class Solution {
public:
    // 动态规划 优化空间复杂度
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        if (row == 0) {
            return 0;
        }
        int col = matrix[0].size();
        priority_queue<int, vector<int>, greater<int>> pq;
        while (!pq.empty()) {
            pq.pop();
        }
        vector<int> dp(col, 0);
        int north_west;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int temp = dp[j];
                if (i == 0 && j == 0) {
                    dp[0] = matrix[0][0];
                } else if (i == 0) {
                    dp[j] = dp[j-1] ^ matrix[i][j];
                } else if (j == 0) {
                    dp[j] = dp[j] ^ matrix[i][j];
                } else {
                    // 需要预存西北角
                    dp[j] = north_west ^ dp[j-1] ^ dp[j] ^ matrix[i][j];
                }
                if (pq.size() < k) {
                    pq.push(dp[j]);
                } else {
                    if (dp[j] > pq.top()) {
                        pq.pop();
                        pq.push(dp[j]);
                    }
                }
                north_west = temp; 
            }
        }
        return pq.top();
    }
};
