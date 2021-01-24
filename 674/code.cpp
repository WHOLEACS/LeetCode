class Solution {
public:
    // 双指针
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return len;
        }
        int l = 0, r = 1;
        int solve = 1;
        while (l < len) {
            while (r < len && nums[r] > nums[r - 1]) {
                r++;
            }
            solve = max(solve, r - l);
            l = r;
            r += 1;
        }
        return solve;
    }
};
