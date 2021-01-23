class Solution {
private:
    vector<int> parent;
public:
    Solution() {
        parent.clear();
    }
    // 并查集 找到冗余的边数，如果大于等于森林数，即可取森林数作为解；否则为-1
    // 无重边和自回环
    void init() {
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n == 1) return 0;
        int len = connections.size();
        if (len == 0) return -1;
        parent.resize(n);
        init();
        int edges = 0;
        for (int i = 0; i < len; i++) {
            int left_tree = find(connections[i][0]);
            int right_tree = find(connections[i][1]);
            if (left_tree == right_tree) {
                edges++;
            }
            parent[left_tree] = right_tree;
        }
        int forest = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                forest++;
            }
        }
        if (edges >= forest - 1) return forest - 1;
        return -1;
    }
};
