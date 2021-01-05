class Solution {
public:
	// 较大分组：连续字符长度 >= 3
	// 双指针
    vector<vector<int>> largeGroupPositions(string s) {
		vector<vector<int>> solve;
		solve.clear();
		int len = s.size();
		if (len < 3) return solve;
		int l = 0, r = 1;
		vector<int> temp;
		while (l < len) {
			while (r < len && s[r] == s[l]) {
				r++;
			}
			if (r - l >= 3) {
				temp.clear();
				temp.emplace_back(l);
				temp.emplace_back(r-1);
				solve.emplace_back(temp);
			}
			l = r;
			r++;
		}
		return solve;
    }
};
