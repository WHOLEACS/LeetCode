class Solution {
private:
    int parent[200];
public:
    Solution() {
        for (int i = 0; i < 200; i++) {
            parent[i] = i;
        }
    }
    int find(int ind) {
        return parent[ind] == ind ? ind : parent[ind] = find(parent[ind]);
    }
    // 并查集--本质是树型结构
    int findCircleNum(vector<vector<int>>& isConnected) {
        int len = isConnected.size();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (isConnected[i][j] == 1 && parent[i] != parent[j]) {
                    int tree_left = find(j);
                    int tree_right = find(i);
                    parent[tree_left] = tree_right;
                }
            }
        }
        int solve = 0;
        for (int i = 0; i < len; i++) {
            if (parent[i] == i) {
                solve++;
            }
        }
        return solve;
    }
};
