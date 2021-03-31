class Solution {
public:
    // 时间复杂度：O(log(row) + log(col))
    // 先按照第一列来查找具体行数，第二步按照行来进行二分
    int col_binary_search(const vector<vector<int>>& matrix, const int& target) {
        int l = 0, r = matrix.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (matrix[mid][0] == target) {
                return mid;
            } else if (matrix[mid][0] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool row_binary_search(const vector<vector<int>>& matrix, const int& target, const int& line) {
        int l = 0, r = matrix[0].size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (matrix[line][mid] == target) {
                return true;
            } else if (matrix[line][mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (l >= matrix[line].size()) {
            return false;
        }
        return matrix[line][l] == target;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0) {
            return false;
        }
        int col = matrix[0].size();
        int line = col_binary_search(matrix, target);
        if (line < row && matrix[line][0] == target) {
            return true;
        }
        line--;
        if (line < 0) {
            return false;
        }
        bool flag = row_binary_search(matrix, target, line);
        return flag;
    }
};
