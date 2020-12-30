// 最大矩形面积 矩形内部元素均为1
typedef pair<int, int> PII;
class Solution {
public:
	int calc(const vector<int>& height) {
		// 单调递增栈，从栈底到栈顶依次递增
		stack<PII> st;
		while (!st.empty()) st.pop();
		int ans = 0, len = height.size();
        //对于每一个元素寻找左边界和右边界
		for (int i = 0; i < len; i++) {
			if (st.empty() || height[i] > height[st.top().first]) {
				st.push(make_pair(i, i));
			} else {
				int left = i;
				while (!st.empty() && height[i] <= height[st.top().first]) {
					ans = max(ans, height[st.top().first] * (i - st.top().second));
					left = min(left, st.top().second);
					st.pop();
				}
				st.push(make_pair(i, left));
			}
		}
		while (!st.empty()) {
			ans = max(ans, (len - st.top().second) * height[st.top().first]);
			st.pop();
		}
		return ans;
	}
	// 单调栈 时间复杂度；O(2*m*n) 空间复杂度：O(n) 
    int maximalRectangle(vector<vector<char>>& matrix) {
		int row = matrix.size();
		if (row == 0) return 0;
		int col = matrix[0].size();
		vector<int> height(col, 0);
		int solve = 0;
		for (int i = 0; i < row; i++) {
			// 更新height数组，带入单调栈进行计算
			for (int j = 0; j < col; j++) {
				height[j] = matrix[i][j] == '0' ? 0 : height[j] + 1;
			}
			solve = max(solve, calc(height));
		}
		return solve;
    }
};
