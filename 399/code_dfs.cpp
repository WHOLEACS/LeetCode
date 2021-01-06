typedef pair<int, double> PII;
class Solution {
private:
	vector<vector<PII>> graph;
	map<string, int> mp;
	double val;
	vector<bool> done;
public:
	Solution() {
		graph.clear();
		mp.clear();
		done.clear();
	}
	// 递归：返回值 调用单元 终止条件
	bool dfs(int index, const int& end_index, double value) {
		if (index == end_index) {
			val = value;
			return true;
		}
		for (int i = 0; i < graph[index].size(); i++) {
			double temp = value * graph[index][i].second;
			if (!done[graph[index][i].first]) {
				done[graph[index][i].first] = true;
				if (dfs(graph[index][i].first, end_index, temp)) return true;
				done[graph[index][i].first] = false;
			}
		}
		return false;
	}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		int len = equations.size();
		graph.resize(2 * len);
		int ind = 0;
		for (int i = 0; i < len; i++) {
			vector<string> relation = equations[i];
			if (mp.find(relation[0]) == mp.end()) {
				mp[relation[0]] = ind;
				ind++;
			}
			int temp = mp[relation[0]];
			if (mp.find(relation[1]) == mp.end()) {
				mp[relation[1]] = ind;
				ind++;
			}
			int dir = mp[relation[1]];
			graph[temp].emplace_back(make_pair(dir, values[i]));
			graph[dir].emplace_back(make_pair(temp, 1.0 / values[i]));
		}
		done.resize(2 * len, false);
		// 遍历query，dfs找到图的路径
		vector<double> solve;
		solve.clear();
		for (int i = 0; i < queries.size(); i++) {
			if (mp.find(queries[i][0]) == mp.end() || mp.find(queries[i][1]) == mp.end()) {
				solve.emplace_back(-1.0);
				continue;
			}
			if (queries[i][0] == queries[i][1]) {
				solve.emplace_back(1.0);
				continue;
			}
            for (int i = 0; i < 2*len; i++) {
                done[i] = false;
            }
			done[mp[queries[i][0]]] = true;
			if (dfs(mp[queries[i][0]], mp[queries[i][1]], 1.0)) {
				solve.emplace_back(val);
			} else {
				solve.emplace_back(-1.0);
			}
		}
		return solve;
    }
};
