class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;
        int len = nums.size();
        if (len == 1) return;
        vector<int> solve(len);
        for (int i = 0; i < len; i++) {
            solve[(i + k) % len] = nums[i];
        }
        nums = solve;
    }
};
