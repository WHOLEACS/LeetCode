// 最大矩形面积 矩形内部元素均为1
class Solution {
public:
	// 暴力优化 时间复杂度：O(m^2 * n) 空间复杂度：O(m*n)
    int maximalRectangle(vector<vector<char>>& matrix) {
		int row = matrix.size();
		if (row == 0) return 0;
		int col = matrix[0].size();
		vector<vector<int>> left(row, vector<int>(col, 0));
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    if (j == 0) {
                        left[i][j] = 1;
                    } else {
                        left[i][j] = left[i][j-1] + 1;
                    }
                }               
			}
		}
		int solve = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (matrix[i][j] == '1') {
					//向上查找，寻找以当前点为矩形右下角的最大面积
					int temp = i, min_width = 0x3f3f3f3f;
					while (temp >= 0 && matrix[temp][j] == '1') {
						min_width = min(min_width, left[temp][j]);
						solve = max(solve, min_width * (i - temp + 1));
						temp--;
					}
				}
			}
		}
		return solve;
    }
};
