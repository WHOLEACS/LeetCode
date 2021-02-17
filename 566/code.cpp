class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size();
        int col = nums[0].size();
        if (row * col != r * c) {
            return nums;
        }
        vector<vector<int>> solve(r, vector<int>(c, 0));
        int tot = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                solve[i][j] = nums[tot/col][tot%col];
                tot++;
            }
        }
        return solve;
    }
};
