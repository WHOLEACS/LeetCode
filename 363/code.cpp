class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        int solve = INT_MIN;
        int ans = k;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int dp[105][105];
                for (int k = 0; k < row; k++) {
                    for (int l = 0; l < col; l++) {
                        dp[k][l] = 0;
                    }
                }
                for (int k = i; k < row; k++) {
                    for (int l = j; l < col; l++) {
                        dp[k][l] = (k-1>=0 ? dp[k-1][l] : 0) + (l-1>=0 ? dp[k][l-1] : 0) - (k-1>=0 && l-1>=0 ? dp[k-1][l-1] : 0) + matrix[k][l];
                        if (dp[k][l] <= ans && dp[k][l] > solve) {
                            solve = dp[k][l];
                        }
                    }
                }
            }
        }
        return solve;
    }
};
