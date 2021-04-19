class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int solve = 0;
        for (int i = 0; i < costs.size(); i++) {
            if (coins <= 0) {
                break;
            }
            coins -= costs[i];
            if (coins >= 0) solve++;
        }
        return solve;
    }
};
