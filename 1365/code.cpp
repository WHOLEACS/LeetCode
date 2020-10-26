class Solution {
public:
	//二分 +　快排
	int rand_index(int l,int r)
	{
		srand(time(NULL));
		return l + rand()%(r-l+1);
	}
	//三路快排 递归：返回值 调用单元 终止条件
	void quick_sort(vector<int>& nums,int l,int r)
	{
		if(l>=r) return;
		int index = rand_index(l,r);
		int temp = nums[index];
		int lone = l , rone = l , ltwo = r;
		while(rone <= ltwo)
		{
			if(nums[rone] == temp) {
				rone++;
			}
			else if(nums[rone] < temp) {
				swap(nums[rone],nums[lone]);
				rone++;
				lone++;
			}
			else {
				swap(nums[rone],nums[ltwo]);
				ltwo--;
			}
		}
		if(rone > r || nums[rone] != temp) rone--;
		if(nums[ltwo] == temp) ltwo++;
		quick_sort(nums,l,lone-1);
		quick_sort(nums,rone+1,r);
	}
	int my_brany_search(const vector<int>& nums,const int& target)
	{
		int l = 0 , r = nums.size();
		while(l<r)
		{
			int mid = l+((r-l)>>1);
			if(nums[mid] >= target) {
				r = mid;
			}
			else {
				l = mid+1;
			}
		}
		return l;
	}
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		int len = nums.size();
		vector<int> nums1 = nums;
		quick_sort(nums,0,len-1);
		vector<int> solve;
		solve.clear();
		for(int i=0;i<nums1.size();i++)
		{
			solve.push_back(my_brany_search(nums,nums1[i]));
		}
		return solve;
    }
};
