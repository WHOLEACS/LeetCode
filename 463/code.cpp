const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
class Solution {
public:
	//时间复杂度：O(4*n*m) 空间复杂度：O(1)
    int islandPerimeter(vector<vector<int>>& grid) {
		int r = grid.size();
		if(r == 0) return 0;
		int c = grid[0].size();
		int solve = 0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(grid[i][j]==1) {
					int num = 0;
					for(int k=0;k<4;k++)
					{
						int nx = i+dx[k] , ny = j+dy[k];
						if(nx>=0&&nx<r&&ny>=0&&ny<c&&grid[nx][ny]==1) {
							num++;
						}
					}
					solve += (4-num);
				}
			}
		}
		return solve;
    }
};
