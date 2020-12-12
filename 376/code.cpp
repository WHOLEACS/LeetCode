class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len < 2) {
            return 1;
        }
        int up = 1, down = 1;
        for (int i = 1; i < len; i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] > nums[i - 1]) {
                up = down + 1;
            }
            else {
                down = up + 1;
            }
        }
        return max(up, down);
    }
};
