class Solution {
public:
	//在有序区间内加入一个区间使得最终得到的区间依然有序
	//时间复杂度：O(n) 空间复杂度：O(n)
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int len = intervals.size();
		vector<vector<int>> solve;
		solve.clear();
		if(len == 0) {
			solve.push_back(newInterval);
			return solve;
		}
		int l = -1 ,r = -1;
		vector<int> vec;
		vec.clear();
		bool flag = false;
		for(int i = 0; i < len; i++)
		{
			int now_l = intervals[i][0];
			int now_r = intervals[i][1];
			bool now_flag = false;
			//寻找当前位置是否是插入位置
			if(!flag && newInterval[0] <= intervals[i][0]) {
				now_l = newInterval[0];
				now_r = newInterval[1];
				flag = true;
				now_flag = true;
			}
			if(l == -1 && r == -1) {
				l = now_l;
				r = now_r;
			}
			if(r >= now_l) r = max(r , now_r);
			else {
				vec.clear();
				vec.push_back(l);
				vec.push_back(r);
				solve.push_back(vec);
				l = now_l;
				r = now_r;
			}
			if(flag && now_flag) i--;
		}
		if(r >= newInterval[0]) {
			r =	max(r , newInterval[1]);
		}
		vec.clear();
		vec.push_back(l);
		vec.push_back(r);
		solve.push_back(vec);
		if(r < newInterval[0]) {
			solve.push_back(newInterval);
		}
		return solve;
    }
};
