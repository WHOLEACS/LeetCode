class Solution {
private:
	vector<int> dp;
public:
	//递归：返回值 调用单元 终止条件
	int calc(int floor, const vector<int>& cost) {
		if (floor <= 1) return dp[floor] = 0;
		if (dp[floor] != -1) return dp[floor];
		return dp[floor] = min(calc(floor - 1, cost) + cost[floor - 1], calc(floor - 2, cost) + cost[floor - 2]);
	}
	//记忆化搜索
    int minCostClimbingStairs(vector<int>& cost) {
		int len = cost.size();
		if (len == 2) return min(cost[0], cost[1]);
		dp.resize(len + 1, -1);
		return calc(len, cost);
    }
};
