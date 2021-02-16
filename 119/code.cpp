typedef long long LL;
class Solution {
public:
    // 杨辉三角的第k行
    // C(rowIndex, idx) = C(rowIndex - 1, idx) + C(rowIndex - 1, idx - 1) dp 时间复杂度：O(k*k)
    // 利用公式 时间复杂度：O(k)
    int calc(int& idx, int& rowIndex) {
        LL ans = 1;
        int temp = max(idx, rowIndex - idx);
        for (int i = temp + 1; i <= rowIndex; i++) {
            ans *= 1l*i;
            ans /= 1l*(1l*i - temp);
        }
        return ans;
    }
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        vector<int> solve = {1};
        for (int i = 1; i < rowIndex; i++) {
            int temp = calc(i, rowIndex);
            solve.emplace_back(temp);
        }
        solve.emplace_back(1);
        return solve;
    }
};
