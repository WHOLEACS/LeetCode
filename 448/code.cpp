class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int temp = nums[i];
            if (nums[i] < 0) {
                temp = -temp;
            }
            if (nums[temp - 1] > 0) {
                nums[temp - 1] = -nums[temp - 1];
            }
        }
        vector<int> solve;
        solve.clear();
        for (int i = 0; i < len; i++) {
            if (nums[i] > 0) {
                solve.emplace_back(i + 1);
            }
        }
        return solve;
    }
};
