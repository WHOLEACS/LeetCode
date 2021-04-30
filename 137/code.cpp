class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            u_int mask = 1 << i, flag = 0;
            for (int& it : nums) {
                if (it & mask) {
                    flag ++;
                }
            }
            if (flag % 3) {
                ans ^= mask;
            }
        }
        return ans;
    }
};
