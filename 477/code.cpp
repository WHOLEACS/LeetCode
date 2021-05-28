class Solution {
public:
    // 任意两个数汉明距离的总和
    // 依次统计每个位的贡献，对于i位置，根据异或性质，只有异号时有贡献，统计nums数组中每个数在该位置是0还是1
    // 假设有在i位上有c个1，那么就有(n-c)个0，那么i位的贡献为(n-c)*c
    int totalHammingDistance(vector<int>& nums) {
        int solve = 0, len = nums.size();
        for (int i = 0; i < 30; i++) {
            int zero = 0;
            for (int& val : nums) {
                if (!((val>>i)&1)) {
                    zero++;
                }
            }
            solve += (len - zero) * zero;
        }
        return solve;
    }
};
