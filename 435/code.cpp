class Solution {
public:
	static bool cmp(const vector<int>& a, const vector<int>& b) {
		return a[1] < b[1];
	}
	// 移除最少的区间，使得剩余区间不重叠  =  得到最长的无重叠的区间
    // 贪心法
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int len = intervals.size();
        if (len == 0) return 0;
		sort(intervals.begin(), intervals.end(), cmp);
		int last_right = intervals[0][1];
		int solve = 0;
		for (int i = 1; i < len; i++) {
			if (last_right > intervals[i][0]) {
				solve++;
				continue;
			}
			last_right = intervals[i][1];
		}
		return solve;
    }
};
