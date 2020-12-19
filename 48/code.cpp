class Solution {
public:
    //原地矩阵旋转
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row <= 1) return;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //以中间列为中心，左右交换
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row/2; j++) {
                swap(matrix[i][j], matrix[i][row-1-j]);
            }
        }
        return;
    }
}; 
