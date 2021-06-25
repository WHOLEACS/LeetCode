class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        // 前缀和数组
        int len = nums.size();
        vector<vector<int>> sum(len + 1, vector<int>(105, 0));
        for (int i = 1; i < len + 1; i++) {
            sum[i] = sum[i-1];
            sum[i][nums[i-1]] += 1;
        }
        int query = queries.size();
        vector<int> solve(query);
        for (int i = 0; i < query; i++) {
            int l = queries[i][0], r = queries[i][1];
            vector<int> pre = sum[l];
            vector<int> after = sum[r+1];
            int temp = -1, p;
            for (int j = 1; j <= 100; j++) {
                if (after[j] - pre[j] > 0) {
                    if (temp == -1) {
                        temp = 0x3f3f3f3f;
                    } else {
                        temp = min(temp, j - p);
                    }
                    p = j;
                }
            }
            solve[i] = temp == 0x3f3f3f3f ? -1 : temp;
        }
        return solve;
    }
};
