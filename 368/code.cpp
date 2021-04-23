class Solution {
public:
    // 时间复杂度：O(n^2)
    // 其实只需要考虑一个整除的方向即可，即使前面较小的元素集合不正确，但是最终答案是正确的
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return nums;
        }
        // 方便进行dp，保证一个数整除比他小的数时，下标不会超过当前元素
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> mp;
        mp.clear();
        for (int i = 0; i < len; i++) {
            vector<int> temp = {nums[i]};
            mp[i] = temp;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    // 可以进行转移
                    if (mp[j].size() + 1 > mp[i].size()) {
                        temp = mp[j];
                        temp.emplace_back(nums[i]);
                        mp[i] = temp;
                    }
                }
            }
        }
        int solve = 0;
        vector<int> ans;
        for (auto& it : mp) {
            if ((it).second.size() > solve) {
                solve = (it).second.size();
                ans = (it).second;
            }
        }
        return ans;
    }
};
