typedef pair<int,int> PII;
class Solution {
public:
	// 大顶堆 时间复杂度：O(n) 空间复杂度：O(K)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		priority_queue<PII> pq;
		while (!pq.empty()) pq.pop();
		for (int i = 0; i < K; i++)
		{
			pq.push(make_pair(points[i][0] * points[i][0] + points[i][1] * points[i][1] , i));
		}
		for (int i = K; i < points.size(); i++)
		{
			PII top = pq.top();
			int length = points[i][0] * points[i][0] + points[i][1] * points[i][1];
			if (length < top.first) {
				pq.pop();
				pq.push(make_pair(length , i));
			} 
		}
		vector<vector<int>> solve;
		solve.clear();
		while (!pq.empty())
		{
			solve.emplace_back(points[pq.top().second]);
			pq.pop();
		}
		return solve;
    }
};
