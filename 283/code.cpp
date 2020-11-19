class Solution {
public:
	//空间复杂度：O(1) 时间复杂度：O(n)
	//双指针
    void moveZeroes(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1) return;
		int index_zero = 0, index_no_zero = 1;
		while (index_zero < index_no_zero && index_no_zero < len)
		{
			while (index_zero < len && nums[index_zero]) {
				index_zero++;
			}
			index_no_zero = index_zero + 1;
			while (index_no_zero < len && nums[index_no_zero] == 0) {
				index_no_zero++;
			}
			if(index_no_zero < len) swap(nums[index_zero], nums[index_no_zero]);
			index_zero++, index_no_zero++;
		}
		return;
    }
};
