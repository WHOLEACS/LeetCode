class Solution {
public:
	//找到<=N 的最大的各个位是单调递增的整数
	//搜索剪枝 : 最大整数 单调递增 注意 10 -> 9这种情况，如果前面的元素小于原来的元素，那么后面的搜索都可以从9开始
	bool dfs(const string& temp, string& solve, int index, int last, bool flag) {
		if (index == temp.size()) return true;
		int max_digit = temp[index] - '0';
		if (flag) max_digit = 9;
		bool flag1 = flag;
		for (int i = max_digit; i >= 0; i--) {
			if (i >= last) {
				if (!flag1 && i < max_digit) {
					flag1 = true;
				}
				solve += i + '0';
				if (dfs(temp, solve, index + 1, i, flag1)) return true;
				solve.pop_back();
			}
			else {
				break;
			}
		}
		return false;
	}
    int monotoneIncreasingDigits(int N) {
		if (N < 10) return N;
		string temp = "";
		while (N) {
			temp += '0' + (N%10);
			N /= 10;
		}
		reverse(temp.begin(), temp.end());
		string solve = "";
		bool flag = false;
		dfs(temp, solve, 0, -1, flag);
		int ans = 0;
		for (int i = 0; i < solve.size(); i++) {
			ans = ans * 10 + (solve[i] - '0');
		}
		return ans;
    }
};
