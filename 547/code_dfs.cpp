class Solution {
private:
    bool done[200];
public:
    // dfs
    Solution() {
        memset(done, false, sizeof(done));
    }
    // 递归：返回值 调用单元 终止条件
    void dfs(const vector<vector<int>>& isConnected, int index) {
        for (int i = 0; i < isConnected[index].size(); i++) {
            if (i == index) {
                continue;
            }
            if (isConnected[index][i] == 1 && !done[i]) {
                done[i] = true;
                dfs(isConnected, i);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int len = isConnected.size(), solve = 0;
        for (int i = 0; i < len; i++) {
            if (!done[i]) {
                // 从没有染色的节点开始
                done[i] = true;
                dfs(isConnected, i);
                solve++;
            }
        }
        return solve;
    }
};
