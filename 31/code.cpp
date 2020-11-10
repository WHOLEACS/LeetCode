class Solution {
public:
	// 时间复杂度：O(n) 空间复杂度：O(1)
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
		if (len <= 1) return;
		//找到最后一个高点
		int last = 0;
		for (int i = 1; i < len; i++)
		{
			if (nums[i] > nums[i-1]) last = i;
		}
		if(last == 0) {
			reverse(nums.begin() , nums.end());
			return;
		}
		if(last == len - 1) {
			swap(nums[len-1] , nums[len-2]);
			return;
		}
		//从高点后找到最后一个大于高点左边的数的临界值
		int index = last;
		while (index < len && nums[index] > nums[last-1]) {
			index++;
		}
		swap(nums[index-1] , nums[last-1]);
		for (int i = 0; i < (len - last)/2; i++)
		{
			swap(nums[i+last] , nums[len-1-i]);
		}
		return;
    }
};
