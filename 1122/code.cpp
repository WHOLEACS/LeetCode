unordered_map<int,int> mp;
class Solution {
private:	
public:
	//时间复杂度：O(n) 空间复杂度：O(n)
    //自定义排序
	static bool cmp(const int& compare_a, const int& compare_b)
	{
		if (mp.find(compare_a) != mp.end() && mp.find(compare_b) != mp.end()) {
			return mp[compare_a] < mp[compare_b];
		}
		else if (mp.find(compare_a) != mp.end() || mp.find(compare_b) != mp.end()) {
			if(mp.find(compare_a) != mp.end()) return true;
			return false;
		}
		else {
			return compare_a < compare_b;
		}
	}
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		int len_2 = arr2.size();
		for (int i = 0; i < len_2; i++)
		{
			mp[arr2[i]] = i;
		}
		sort(arr1.begin(), arr1.end(), cmp);
		return arr1;
    }
};
