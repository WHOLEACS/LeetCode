typedef long long LL;
typedef pair<LL, LL> PII;
class Solution {
private:
    struct node{
        int weight;
        int idx;
        node(int weight, int idx) {
            this->weight = weight;
            this->idx = idx;
        }
        node() {
            this->weight = 0;
            this->idx = -1;
        }
        friend bool operator < (const node& a, const node& b) {
            return a.weight == b.weight ? a.idx > b.idx : a.weight > b.weight;
        }
    };
    // 空闲队列
    priority_queue<node> free_pq;
    // 忙碌队列
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    // 任务队列
    queue<PII> task_pq;
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int len_ser = servers.size(), len_tasks = tasks.size();
        if (len_ser == 1 && len_tasks == 1) {
            return {0};
        }
        // 这里表示只有一台服务器的情况
        if (len_ser == 1) {
            vector<int> temp(len_tasks, 0);
            return temp;
        }
        for (int i = 0; i < len_ser; i++) {
            free_pq.push(node(servers[i], i));
        }
        vector<int> solve;
        solve.clear();
        for (int i = 0; i < len_tasks; i++) {
            task_pq.push(make_pair(i, tasks[i]));
            while (!pq.empty() && i >= pq.top().first) {
                free_pq.push(node(servers[pq.top().second], pq.top().second));
                pq.pop();
            }
            while (!free_pq.empty() && !task_pq.empty()) {
                int time = task_pq.front().second;
                task_pq.pop();
                solve.emplace_back(free_pq.top().idx);
                pq.push(make_pair(i + time, free_pq.top().idx));
                free_pq.pop();
            }
        }
        while (!task_pq.empty()) {
            int ans = pq.top().first;
            while (!pq.empty() &&  pq.top().first == ans) {
                free_pq.push(node(servers[pq.top().second], pq.top().second));
                pq.pop();
            }
            while (!free_pq.empty() && !task_pq.empty()) {
                int time = task_pq.front().second;
                task_pq.pop();
                solve.emplace_back(free_pq.top().idx);
                pq.push(make_pair(1l * ans + time, free_pq.top().idx));
                free_pq.pop();
            }
        }
        return solve;
    }
};
