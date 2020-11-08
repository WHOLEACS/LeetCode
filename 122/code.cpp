class Solution {
public:
    //双指针 + 贪心 时间复杂度：O(n) 空间复杂度：O(1)
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        int solve = 0;
        int l = 0 , r = 1;
        while (r < len && l < r)
        {
            if (prices[l] >= prices[r]) {
                l++;
                r++;
            }
            else if (r + 1 < len && prices[r + 1] >= prices[r]) {
                    r++;
            }
            else {
                solve += prices[r] - prices[l];
                l = r + 1;
                r = l + 1;
            }
        }
        return solve;
    }
};
