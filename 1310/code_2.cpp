class Solution {
private:
    vector<int> pre_sum;
public:
    // 树状数组
    int lowbit(int x) {
        return x&(-x);
    }

    // 构建树状数组
    void add (int i, int k) {
        while (i < pre_sum.size()) {
            pre_sum[i] ^= k;
            i += lowbit(i);
        }
    }

    // 查询操作
    int query(int cnt) {
        int ans = 0;
        while (cnt > 0) {
            ans ^= pre_sum[cnt];
            cnt -= lowbit(cnt);
        }
        return ans;
    }

    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int len = arr.size();
        pre_sum.resize(len + 1, 0);
        for (int i = 0; i < len; i++) {
            add(i + 1, arr[i]);
        }
        vector<int> solve;
        solve.clear();
        for (int i = 0; i < queries.size(); i++) {
            solve.emplace_back(query(queries[i][0]) ^ query(queries[i][1] + 1));
        }
        return solve;
    }
};
