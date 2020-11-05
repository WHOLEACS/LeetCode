typedef pair<int,int> PII;
class Solution {
public:
	bool judge(const string& str1, const string& str2)
	{
		int num = 0;
		for (int i = 0; i < str1.size(); i++)
		{
			if(str1[i] == str2[i]) continue;
			num++;
		}
		return num == 1;
	}
	int bfs(int start_index, const string& endWord, const vector<vector<int>>& edges, const vector<string>& wordList)
	{
		vector<bool> done(wordList.size(),false);
		queue<PII> pq;
		while(!pq.empty()) pq.pop();
		pq.push(make_pair(start_index,1));
		done[start_index] = true;
		while(!pq.empty())
		{
			PII now = pq.front();
			pq.pop();
			if(wordList[now.first] == endWord) return now.second;
			for (int i=0;i<edges[now.first].size();i++)
			{
				if(!done[edges[now.first][i]]) {
					pq.push(make_pair(edges[now.first][i],now.second+1));
					done[edges[now.first][i]] = true;
				}
			}
		}
		return 0;
	}
	//构建一张无向图 图中的相邻节点表示两个字符串只有一个字母不同，能够相互转换
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size();
		if (len < 1) return 0;
		bool end = false;
		vector<vector<int>> edges(len+1);
		int start_index = -1;
		for (int i = 0; i < len; i++)
		{
			if (wordList[i] == beginWord) start_index = i;
			if (wordList[i] == endWord) end = true;
			if (i == len - 1) continue;
			for (int j = i+1; j < len; j++)
			{
				if (judge(wordList[i] , wordList[j])) {
					edges[i].emplace_back(j);
					edges[j].emplace_back(i);
				}
			}
		}
		if (!end) return 0;
		if (start_index == -1) {
			start_index = len;
			wordList.emplace_back(beginWord);
			for (int i = 0; i < len; i++)
			{
				if (judge(wordList[i], beginWord)) {
					edges[len].emplace_back(i);
					edges[i].emplace_back(len);
				}
			}
		}
		//bfs
		return bfs(start_index, endWord, edges, wordList);
    }
};
