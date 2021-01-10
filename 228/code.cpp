class Solution {
public:
    // 双指针 时间复杂度：O(n) 空间复杂度：O(n)
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> solve;
        solve.clear();
        int len = nums.size();
        if (len == 0) return solve;
        if (len == 1) return {to_string(nums[0]),};
        int l = 0, r = 1;
        while (l < len) {
            int temp = l;
            while (r < len && 1L*nums[r] - 1L*nums[temp] <= 1) {
                temp = r;
                r++;
            }
            string str = "";
            if (r - l > 1) {
                str += to_string(nums[l]);
                str += "->";
                str += to_string(nums[temp]);
            } else {
                str += to_string(nums[l]);
            }
            solve.emplace_back(str);
            l = r;
            r++;
        }
        return solve;
    }
};
