typedef pair<int, int> PII;
class Solution {
public:
    bool binary_search(const vector<vector<int>>& matrix, const int& target, const int& row, const int& col) {
        int l = 0, r = row * col;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (matrix[mid/col][mid%col] == target) {
                return true;
            } else if (matrix[mid/col][mid%col] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
    // 一次二分 时间复杂度：O(log(n*m)) 空间复杂度：O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0) {
            return false;
        }
        int col = matrix[0].size();
        return binary_search(matrix, target, row, col);
    }
};
