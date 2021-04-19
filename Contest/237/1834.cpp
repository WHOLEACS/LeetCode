typedef long long LL;
class Solution {
private:
    struct node {
        int time, idx;
        node(int time, int idx) {
            this->time = time;
            this->idx = idx;
        }
        friend bool operator < (const node& a, const node& b) {
            return a.time == b.time ? a.idx > b.idx : a.time > b.time;
        }
    };
public:
    // 优先队列
    vector<int> getOrder(vector<vector<int>>& tasks) {
        if (tasks.size() == 0) {
            return {};
        }
        map<int, vector<int>> mp;
        mp.clear();
        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i][0]].emplace_back(i);
        }
        priority_queue<node> pq;
        while (!pq.empty()) {
            pq.pop();
        }
        vector<int> solve;
        solve.clear();
        auto idx = mp.begin();
        LL time = (*idx).first;
        for (auto it : (*idx).second) {
            pq.push(node(tasks[it][1], it));
        }
        idx++;
        while (!pq.empty()) {
            node k = pq.top();
            pq.pop();
            solve.emplace_back(k.idx);
            time += 1l * k.time;
            // 当任务时间连续不起来的时候需要特别注意这里的坑
            if (pq.empty() && idx != mp.end() && time < (*idx).first) {
                time = (*idx).first;
            }
            while (idx != mp.end() && (*idx).first <= 1l * time) {
                for (auto it : (*idx).second) {
                    pq.push(node(tasks[it][1], it));
                }
                idx++;
            }
        }
        return solve;
    }
};
