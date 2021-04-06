class Solution {
public:
    // 时间复杂度：O(n) 空间复杂度：O(n)
    int numRabbits(vector<int>& answers) {
        int len = answers.size();
        if (len == 0) {
            return len;
        }
        unordered_map<int, int> mp;
        mp.clear();
        for (int y: answers) {
            ++mp[y];
        }
        int solve = 0;
        for (auto& [y,x] : mp) {
            solve += (int)ceil((float)x/(y+1)) * (y+1); 
        }
        return solve;
    }
};
