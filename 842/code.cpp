typedef long long LL;
class Solution {
private:
	vector<int> vec;
public:
	Solution() {
		vec.clear();
	}
	//搜索剪枝 每个数都在int范围内 且 0不能开头,除非单作为一个数字 且结果数组必须长度>=3
	LL intval(const string& target) {
		int len = target.size();
		LL solve = 0;
		for (int i = 0; i < len; i++) {
			solve = 1l * solve * 10 + (target[i] - '0');
		}
		return solve;
	}
	//递归：返回值 调用单元 终止条件
	bool dfs(const string& S, int index) {
		if (index == S.size()) return true;
		int len = vec.size();
		if (S[index] == '0' && vec[len - 1] + vec[len - 2] != 0) return false;
		LL temp = 1l * vec[len - 1] + vec[len - 2];
		string now_target = to_string(temp);
		if (S.size() - index < now_target.size() || now_target != S.substr(index, now_target.size()) || now_target.size() > 12 || intval(now_target) > INT_MAX) return false;
		vec.emplace_back(vec[len-1] + vec[len-2]);
		if (!dfs(S, index + now_target.size())) {
			vec.pop_back();
			return false;
		}
		return true;
	}
    vector<int> splitIntoFibonacci(string S) {
		int len = S.size();
		if (len < 3) return {};
		for (int i = 0; i < len - 2; i++) {
			string temp_first = S.substr(0, i + 1);
			if (temp_first.size() > 12 || intval(temp_first) > INT_MAX) break;
			vec.emplace_back(intval(temp_first));
			for (int j = i + 1; j < len - 1; j++) {
				string temp_second = S.substr(i + 1, j - i);
				if (temp_second.size() > 12 || intval(temp_second) > INT_MAX) break;
				vec.emplace_back(intval(temp_second));
				if (dfs(S, j + 1)) {
					return vec;
				}
				vec.pop_back();
				if (temp_second == "0") {
					break;
				}
			}
			vec.pop_back();
			if (temp_first == "0") {
				break;
			}
		}
		return {};
    }
};
