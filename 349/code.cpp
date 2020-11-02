class Solution {
public:
	//求两个数组的交集 数组中的元素可能重复，但是最终得到的交集中元素不能重复
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size() , len2 = nums2.size();
		if(len1 == 0 || len2 == 0) return {};
		vector<int> solve;
		solve.clear();
		sort(nums1.begin(),nums1.end());
		sort(nums2.begin(),nums2.end());
		int index_1 = 0 , index_2 = 0;
		while(index_1 < len1 && index_2 < len2)
		{
			if(nums1[index_1] == nums2[index_2]) {
				if(solve.size() == 0 || solve[solve.size()-1] != nums1[index_1]) {
					solve.push_back(nums1[index_1]);
				}
				index_1++ , index_2++;
			}
			else if(nums1[index_1] < nums2[index_2]) {
				index_1++;
			}
			else {
				index_2++;
			}
		}
		return solve;
	}
};
