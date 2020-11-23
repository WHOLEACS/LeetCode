class Solution {
public:
	static bool cmp(const vector<int>& point_1, const vector<int>& point_2) {
		return point_1[0] == point_2[0] ? point_1[1] < point_2[1] : point_1[0] < point_2[0];
	}
	//贪心法 按照起始位置进行排序
    int findMinArrowShots(vector<vector<int>>& points) {
		int len = points.size();
		if (len <= 1) return len;
		sort(points.begin(), points.end(), cmp);
		int last_right = points[0][1] , solve = 1, index = 1;
		while (index < len)
		{
			if (points[index][0] > last_right) {
				solve++;
				last_right = points[index][1];
				
			} else {
				last_right = min(last_right, points[index][1]);
			}
			index++;
		}
		return solve;
    }
};
