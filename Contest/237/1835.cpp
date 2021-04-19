class Solution {
public:
    // 时间复杂度：O(n) 空间复杂度：O(1)
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int a = 0, b = 0;
        for (auto& it : arr1) {
            a ^= it;
        }
        for (auto& it : arr2) {
            b ^= it;
        }
        return a&b;
    }
};
