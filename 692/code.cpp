class Solution {
private:
    struct node{
        int num;
        string str;
        node() {
            this->num = 0;
            this->str = "";
        }
        node(int num, string str) {
            this->num = num;
            this->str = str;
        }
        friend bool operator < (const node& a, const node& b) {
            return a.num != b.num ? a.num > b.num : a.str < b.str;
        }
    };
public:
    // 时间复杂度：O(nlogk) 空间复杂度：O(n)
    vector<string> topKFrequent(vector<string>& words, int k) {
        int len = words.size();
        unordered_map<string, int> mp;
        mp.clear();
        for (string& s : words) {
            mp[s] += 1;
        }
        vector<string> solve;
        solve.clear();
        priority_queue<node> pq;
        while (!pq.empty()) {
            pq.pop();
        }
        // cout << mp["hhqpvvt"] << " " << mp["fvvdtpnzx"] << endl;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (pq.size() < k) {
                pq.push(node((*it).second, (*it).first));
            } else {
                if (pq.top().num < (*it).second || (pq.top().num == (*it).second && pq.top().str > (*it).first)) {
                    pq.pop();
                    pq.push(node((*it).second, (*it).first));
                    // cout << (*it).second << " " << (*it).first << endl; 
                }
            }
            // cout << (*it).second << " " << (*it).first << endl;
        }
        while (!pq.empty()) {
            solve.emplace_back(pq.top().str);
            pq.pop();
        }
        reverse(solve.begin(), solve.end());
        return solve;
    }
};
