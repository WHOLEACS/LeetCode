class Solution {
private:
    struct node {
		int ind;
		char compare;
        node(int ind, char compare) {
            this->ind = ind;
            this->compare = compare;
        }
        friend bool operator< (const node a, const node b) {
            return a.compare > b.compare;
        }
	};
	vector<int> parent;
	unordered_map<int, priority_queue<node>> mp;
public:
	Solution() {
		parent.clear();
		mp.clear();
	}
	int find(int leaf) {
		return leaf == parent[leaf] ? leaf : parent[leaf] = find(parent[leaf]);
	}
	// 并查集+贪心法 每个联通分量内的字符可以任意交换
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
		int len = s.size();
		if (len <= 1) return s;
		parent.resize(len);
		for (int i = 0; i < len; i++) {
			parent[i] = i;
		}
		int nums = pairs.size();
		for (int i = 0; i < nums; i++) {
			int left_tree = find(pairs[i][0]);
			int right_tree = find(pairs[i][1]);
			if (left_tree != right_tree) {
				parent[left_tree] = right_tree;
			}
		}
		for (int i = 0; i < len; i++) {
			mp[find(i)].push(node(i, s[i]));
		}
		for (int i = 0; i < len; i++) {
			s[i] = mp[parent[i]].top().compare;
			mp[parent[i]].pop();
		}
		return s;
    }
};

