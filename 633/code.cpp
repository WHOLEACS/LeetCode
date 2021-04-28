class Solution {
public:
    // 双指针 时间复杂度：O(sqrt(n))
    bool judgeSquareSum(int c) {
        if (c <= 2) {
            return true;
        }
        int l = 0, r = sqrt(c);
        while (l <= r) {
            long long temp = 1l * l * l + 1l * r * r;
            if (temp == c) {
                return true;
            }
            if (temp < c) {
                l++;
            } else {
                r--;
            }
        }
        return false;
    }
};
