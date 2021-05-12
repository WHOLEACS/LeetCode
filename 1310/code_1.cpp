class Solution {
public:
    // 前缀异或打表
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int len = arr.size();
        vector<int> pre_sum(len + 1, 0);
        // pre_sum[i]表示arr数组前i个元素异或的结果
        for (int i = 1; i < len + 1; i++) {
            pre_sum[i] = pre_sum[i-1] ^ arr[i-1];
        }
        vector<int> solve;
        solve.clear();
        for (int i = 0; i < queries.size(); i++) {
            solve.emplace_back(pre_sum[queries[i][1]+1] ^ pre_sum[queries[i][0]]);
        }
        return solve;
    }
};
