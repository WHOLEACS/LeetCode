class Solution {
private:
    int solve = 0;
public:
    // 位运算 + dfs 递归：返回值 调用单元 终止条件
    // 是否填入
    void dfs(int idx, const vector<int>& masks, int ans) {
        if (idx == masks.size()) {
            solve = max(solve, __builtin_popcount(ans));
            return;
        }
        if ((ans & masks[idx]) == 0) {
            // 可以填入
            dfs(idx + 1, masks, ans | masks[idx]);
        } 
        // 不填入
        dfs(idx + 1, masks, ans);
        return;
    }

    int maxLength(vector<string>& arr) {
        vector<int> masks;
        for (int i = 0; i < arr.size(); i++) {
            int mask = 0;
            for (int j = 0; j < arr[i].size(); j++) {
                if ((mask >> (arr[i][j] - 'a')) & 1) {
                    mask = 0;
                    break;
                }
                // 把该位置置为1
                mask |= 1 << (arr[i][j] - 'a');
            }
            if (mask) {
                masks.emplace_back(mask);
            }
        }
        dfs(0, masks, 0);
        return solve;
    }
};
