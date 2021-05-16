class Solution {
private:
    int solve = 0x3f3f3f3f;
public:
    // 递归：返回值 调用单元 终止条件
    void dfs(int idx, const vector<int>& jobs, vector<int> bag, int max_weight, int used) {
        // cout << max_weight << endl;
        // 剪枝
        if (max_weight >= solve) {
            return;
        }
        if (idx >= jobs.size()) {
            solve = min(solve, max_weight);
            return;
        }
        int k = bag.size(), temp;
        // 首先尝试分配给未工作的人，对于没有工作时间的人来说，分配无差别
        if (used < k) {
            bag[used] = jobs[idx];
            dfs(idx + 1, jobs, bag, max(max_weight, bag[used]), used + 1);
            bag[used] = 0;
        }
        // 然后尝试分配给已经工作的人，注意范围为[0,used)，未分配人的情况已经搜索过了，如果范围是[0,k)，那么就会有很多的无用情况产生
        // 随后再暴力尝试
        for (int i = 0; i < used; i++) {
            // 把idx号job放到i背包中
            temp = max_weight;
            bag[i] += jobs[idx];
            if (bag[i] > temp) {
                temp = bag[i];
            }
            if (temp < solve) {
                dfs(idx + 1, jobs, bag, temp, used);
            }
            bag[i] -= jobs[idx];
        }
        return;
    }

    // 搜索
    int minimumTimeRequired(vector<int>& jobs, int k) {
        // 首先找到一个近似解，然后使用暴力逼近
        int len = jobs.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        while (!pq.empty()) {
            pq.pop();
        }
        for (int i = 0; i < k; i++) {
            pq.push(0);
        }
        for (int i = 0; i < len; i++) {
            int now = pq.top();
            pq.pop();
            pq.push(now + jobs[i]);
        }
        int temp = 0;
        while (!pq.empty()) {
            temp = max(temp, pq.top());
            pq.pop();
        }
        solve = temp;
        vector<int> bag(k, 0);
        dfs(0, jobs, bag, 0, 0);
        return solve;
    }
};
