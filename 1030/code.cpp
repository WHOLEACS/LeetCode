const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
typedef pair<int, int> PII;
class Solution {
private:
	vector<vector<int>> solve;
	vector<vector<bool>> done;
public:
	Solution()
	{
		solve.clear();
		done.clear();
	}
	void bfs(const int& R, const int& C, const int&r0, const int& c0)
	{
		queue<PII> pq;
		while(!pq.empty()) pq.pop();
		done.resize(R, vector<bool>(C, false));
		done[r0][c0] = true;
		pq.push(make_pair(r0, c0));
		while(!pq.empty())
		{
			PII now = pq.front();
			pq.pop();
			solve.push_back({now.first, now.second});
			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + now.first , ny = dy[i] + now.second;
				if (nx >= 0 && nx < R && ny >= 0 && ny < C && !done[nx][ny]) {
					done[nx][ny] = true;
					pq.push(make_pair(nx, ny));
				}
			}
		}
	}
	//bfs
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		bfs(R, C, r0, c0);
		return solve;
	}
};
