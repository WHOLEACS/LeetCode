class Solution {
public:
    //注意这里取值的是开区间
	int rand_int(int l, int r)
	{
		return rand()%(r-l)+l;
	}
	//递归：返回值 调用单元 终止条件
	void quick_sort(vector<int>& nums, int l, int r)
	{
		if (l >= r-1) return;
		int index = rand_int(l, r);
		int temp = nums[index];
		int lone = l, rone = l, ltwo = r - 1;
		while (rone <= ltwo) {
			if (nums[rone] == temp) {
				rone++;
			}
			else if(nums[rone] < temp) {
				swap(nums[lone], nums[rone]);
				lone++, rone++;
			}
			else {
				swap(nums[rone], nums[ltwo]);
				ltwo--;
			}
		}
		if (rone >= r || nums[rone] != temp) rone--;
		if (nums[ltwo] == temp) ltwo++;
		quick_sort(nums, l, lone);
		quick_sort(nums, rone + 1, r);
	}
	//时间复杂度：O(nlogn) 空间复杂度：O(1)(此处不计递归栈复杂度)
    int maximumGap(vector<int>& nums) {
		int len = nums.size();
		if (len < 2) return 0;
		quick_sort(nums, 0 , len);
		int solve = 0;
		for (int i = 0; i < len - 1; i++)
		{
			solve = max(solve, nums[i + 1] - nums[i]);
		}
		return solve;
    }
};
