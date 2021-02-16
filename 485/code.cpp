class Solution {
public:
    // 双指针
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, r = 0, len = nums.size();
        while (l < len && !nums[l]) {
            l++;
        }
        r = l + 1;
        int solve = 0;
        while (l < len) {
            while (r < len && nums[r] == 1) {
                r++;
            }
            solve = max(solve, r - l);
            while (r < len && !nums[r]) {
                r++;
            }
            l = r;
            r = l + 1;
        }
        return solve;
    }
};
