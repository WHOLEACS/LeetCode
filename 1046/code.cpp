class Solution {
public:
	// 维护一个大顶堆 
    int lastStoneWeight(vector<int>& stones) {
		int len = stones.size();
		if (len == 1) {
			return stones[0];
		}
		priority_queue<int> pq;
		while (!pq.empty()) {
			pq.pop();
		}
		for (int i = 0; i < stones.size(); i++) {
			pq.push(stones[i]);
		}
		while (!pq.empty()) {
			if (pq.size() == 1) break;
			int temp_1 = pq.top();
			pq.pop();
			int temp_2 = pq.top();
			pq.pop();
			if (temp_2 == temp_1) continue;
			pq.push(temp_1 - temp_2);
		}
		return pq.empty() ? 0 : pq.top();
    }
};

