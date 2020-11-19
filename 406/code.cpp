class Solution {
public:
	//贪心法  优先把靠后的元素放到空位置上，这样就变成了插空的操作
	//首先按照h值排序，按照h值从小到大排序，因为矮个子靠后方便高个子插到前面的空位置上；如果h值相等，那么需要按照第二个值从大到小排序，同理，这也是为了
	//方便插值
	static bool cmp(const vector<int>& param_vec_1, const vector<int>& param_vec_2)
	{
		return param_vec_1[0] == param_vec_2[0] ? param_vec_1[1] > param_vec_2[1] : param_vec_1[0] < param_vec_2[0];
	}
	//将第i个人放到第Ki+1个空位置
	//时间复杂度：O(n^2)
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int len = people.size();
		if (len <= 1) return people;
		sort(people.begin(), people.end(), cmp);
		vector<vector<int>> solve(len, vector<int>(2,-1));
		for (int i = 0; i < len; i++)
		{
			int space = people[i][1];
			int j = 0;
			for(; j < len && space; j++)
			{
				if (solve[j][0] == -1) space--;
			}
			while (j < len && solve[j][0] != -1) j++;
			if (j < len) solve[j] = people[i];
		}
		return solve;
    }
};
