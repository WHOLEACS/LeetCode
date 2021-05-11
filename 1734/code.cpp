class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        vector<int> solve;
        // 确定第一个j0
        int k = 0;
        for (int i = 1; i <= n; i++) {
            k ^= i;
        }
        int f = 0;
        for (int i = 1; i < n; i += 2) {
            f ^= encoded[i];
        }
        int i = k ^ f;
        solve.clear();
        solve.emplace_back(i);
        int temp = encoded[0];
        for (int j = 1; j < n; j++) {
            int ans = i^temp;
            solve.emplace_back(ans);
            if (j < n - 1) {
                temp ^= encoded[j];
            }
        }
        return solve;
    }
};
