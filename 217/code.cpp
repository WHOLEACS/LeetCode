class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1) return false;
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < len - 1; i++) {
			if (nums[i] == nums[i + 1]) return true;
		}
		return false;
	}
};
