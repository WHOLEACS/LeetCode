class Solution {
public:
    // 数量 逆转 0 1 2 3
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int row_1 = mat.size(), col_1 = mat[0].size();
        int row_2 = target.size(), col_2 = target[0].size();
        if (row_1 != row_2 || col_1 != col_2) {
            return false;
        }
        int one_1 = 0, zero_1 = 0;
        int one_2 = 0, zero_2 = 0;
        for (int i = 0; i < row_1; i++) {
            for (int j = 0; j < col_1; j++) {
                if (mat[i][j]) {
                    one_1++;
                } else {
                    zero_1++;
                }
            }
        }
        for (int i = 0; i < row_2; i++) {
            for (int j = 0; j < col_2; j++) {
                if (target[i][j]) {
                    one_2++;
                } else {
                    zero_2++;
                }
            }
        }
        if (one_1 != one_2 || zero_1 != zero_2) {
            return false;
        }
        auto judge = [&](vector<vector<int>>& k1, vector<vector<int>>& k2) {
            bool ans = true;
            int row = k1.size();
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < row; j++) {
                    if (k1[i][j] != k2[i][j]) {
                        ans = false;
                        break;
                    }
                }
                if (!ans) {
                    break;
                }
            }
            return ans;
        };
        // 顺时针
        bool flag = judge(mat, target);
        bool flag_1 = true;
        bool flag_2 = true;
        bool flag_3 = true;
        // 旋转一次        
        vector<vector<int>> mat_1(row_1, vector<int>(row_1));
        for (int i = 0; i < row_1; i++) {
            for (int j = 0; j < row_1; j++) {
                mat_1[i][j] = mat[row_1 - 1 - j][i];
            }
        }
        flag_1 = judge(mat_1, target);
        // 旋转两次
        vector<vector<int>> mat_2(row_1, vector<int>(row_2));
        for (int i = 0; i < row_1; i++) {
            for (int j = 0; j < row_1; j++) {
                mat_2[i][j] = mat[row_1 - 1 - i][row_1 - 1 - j];
            }
        }
        flag_2 = judge(mat_2, target);
        // 旋转3次
        vector<vector<int>> mat_3(row_1, vector<int>(row_1));
        for (int i = 0; i < row_1; i++) {
            for (int j = 0; j < row_1; j++) {
                mat_3[i][j] = mat[j][row_1 - 1 - i];
            }
        }
        flag_3 = judge(mat_3, target);
        return flag || flag_1 || flag_2 || flag_3;
    }
};
