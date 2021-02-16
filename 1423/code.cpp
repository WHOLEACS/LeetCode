class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        int solve = -0x3f3f3f3f, sum = 0;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        solve = max(solve, sum);
        for (int i = k - 1; i >= 0; i--) {
            sum -= cardPoints[i];
            sum += cardPoints[len - k + i];
            solve = max(solve, sum);
        }
        return solve;
    }
};
