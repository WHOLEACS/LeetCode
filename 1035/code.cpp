class Solution {
public:
    // 时间复杂度：O(n*m) 空间复杂度：O(m)  n = len(nums1) m = len(nums2) 进行空间优化
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> dp(len2 + 1, 0);
        int west_north;
        for (int i = 1; i <= len1; i++) {
            west_north = dp[0];
            for (int j = 1; j <= len2; j++) {
                int temp = dp[j];
                dp[j] = max(dp[j], max(dp[j-1], west_north + (nums1[i-1] == nums2[j-1] ? 1 : 0)));
                west_north = temp;
            }
        }
        return dp[len2];
    }
};
