class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> mp;
        mp.clear();
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] += 1;
        }
        auto it = mp.end();
        it--;
        int solve = 0;
        int pre = 0;
        for (; it != mp.begin(); it--) {
            solve += pre + (*it).second;
            pre += (*it).second;
        }
        return solve;
    }
};
