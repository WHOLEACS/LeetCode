class Solution {
public:
    // 双指针 时间复杂度：O(n) 空间复杂度：O(1)
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }
        int l = 0, r = 1;
        while (r < len) {
            if (nums[l] != nums[r]) {
                nums[++l] = nums[r];
            }
            r++;
        }
        return l+1;
    }
};
