class Solution {
private:
	unordered_map<string, vector<int>> mp;
	vector<vector<string>> solve;
public:
	Solution() {
		mp.clear();
		solve.clear();
	}
	//字母异位
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		int len = strs.size();
		if (len == 0) return {};
		for (int i = 0; i < len; i++) {
			string now_str = strs[i];
			sort(now_str.begin(), now_str.end());
			mp[now_str].push_back(i);
		}
		vector<string> temp;
		for (auto& iter : mp) {
			temp.clear();
			vector<int> ind = (iter.second);
			for (int i = 0; i < ind.size(); i++)
			{
				temp.emplace_back((strs[ind[i]]));
			}
			solve.emplace_back(temp);
		}
		return solve;
    }
};
