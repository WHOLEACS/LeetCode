const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
typedef pair<int, int> PII;
class Solution {
private:
    bool done[505][505];
    int solve = 0;
    PII parent[505][505];
public:
    // 并查集
    void init(const vector<vector<int>>& grid1) {
        for (int i = 0; i < grid1.size(); i++) {
            for (int j = 0; j < grid1[0].size(); j++) {
                parent[i][j] = make_pair(i, j);
            }
        }
        for (int i = 0; i < grid1.size(); i++) {
            for (int j = 0; j < grid1[0].size(); j++) {
                if (grid1[i][j] == 1) {
                    // 找左边和上边
                    if (j - 1 >= 0 && grid1[i][j-1] == 1) {
                        PII p1 = find(i, j);
                        PII p2 = find(i, j-1);
                        if (p1 != p2) {
                            parent[p1.first][p1.second] = p2;
                        }
                    }
                    if (i - 1 >= 0 && grid1[i-1][j] == 1) {
                        PII p1 = find(i, j);
                        PII p2 = find(i-1, j);
                        if (p1 != p2) {
                            parent[p1.first][p1.second] = p2;
                        }
                    }
                }
            }
        }
    }
    PII find(int x, int y) {
        return x == parent[x][y].first && y == parent[x][y].second ? make_pair(x, y) : parent[x][y] = find(parent[x][y].first, parent[x][y].second);
    }
    // 递归：返回值 调用单元 终止条件
    void dfs(int x, int y, const vector<vector<int>>& grid2, const PII& parent, bool& flag, const vector<vector<int>>& grid1) {
        PII now = find(x, y);
        if (now != parent || grid1[now.first][now.second] == 0) {
            flag = false;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < grid2.size() && ny >= 0 && ny < grid2[0].size() && !done[nx][ny] && grid2[nx][ny] == 1) {
                done[nx][ny] = true;
                dfs(nx, ny, grid2, parent, flag, grid1); 
            }
        }
        return;
    }
    // dfs + 并查集
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // 预处理grid1, 高效查询b中的岛屿中包含的点是否在grid1中属于一个岛屿
        init(grid1);
        int row = grid1.size();
        int col = grid1[0].size();
        memset(done, false, sizeof(done));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!done[i][j] && grid2[i][j] == 1) {
                    // 从当前位置dfs
                    done[i][j] = true;
                    // 查询当前位置的parent岛屿
                    PII parent = find(i, j);
                    bool flag = true;
                    dfs(i, j, grid2, parent, flag, grid1);
                    if (flag) {
                        solve++;
                    }
                }
            }
        }
        return solve;
    }
};
