class Solution {
public:
	int my_lower(const vector<int>& nums, const int& target) {
		int l = 0, r = nums.size();
		while (l < r) {
			int mid = l + ((r - l)>>1);
			if (nums[mid] >= target) r = mid;
			else l = mid + 1;
		}
		return l < nums.size() && nums[l] == target ? l : -1;
	}
	int my_upper(const vector<int>& nums, const int& target) {
		int l = 0, r = nums.size();
		while (l < r - 1) {
			int mid = l + ((r - l)>>1);
			if (nums[mid] > target) r = mid;
            //注意这里的l指针的变化，如果设置成mid+1那么不符合当前的二分判断，可能会造成l指向和r相同的位置造成错误
			else l = mid;
		}
		return l < nums.size() && nums[l] == target ? l : -1;
	}
	//二分查找  时间复杂度：O(logn)
    vector<int> searchRange(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 0) return {-1, -1};
		return {my_lower(nums, target), my_upper(nums, target)};
    }
};
