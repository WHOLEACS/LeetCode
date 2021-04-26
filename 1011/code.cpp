class Solution {
public:
    // 二分 时间复杂度：O(nlogsum) 空间复杂度：O(1)
    int shipWithinDays(vector<int>& weights, int D) {
        int sum = 0, max_weight = -0x3f3f3f3f, len = weights.size();
        for (int& it : weights) {
            sum += it;
            max_weight = max(max_weight, it);
        }
        if (D == 1) {
            return sum;
        }
        if (D == len) {
            return max_weight;
        }
        // 左闭右闭
        int l = max_weight, r = sum - 1;
        while (l < r) {
            // mid指的是当前的最低运载能力
            int mid = (l + r) >> 1;
            // 求出当前运载能力对应的天数
            int idx = 0, day = 0;
            while (idx < len) {
                int temp = mid;
                while (temp > 0 && idx < len && temp >= weights[idx]) {
                    temp -= weights[idx];
                    idx++;
                }
                day++;
            }
            if (day > D) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
