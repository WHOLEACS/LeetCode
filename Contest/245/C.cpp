class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        for (int i = 0; i < triplets.size(); i++) {
            if (target[0] == triplets[i][0] && target[1] == triplets[i][1] && target[2] == triplets[i][2]) {
                return true;
            }
        }
        vector<int> state(3, 0);
        for (int i = 0; i < triplets.size(); i++) {
            if (triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]) {
                state[0] = max(state[0], triplets[i][0]);
                state[1] = max(state[1], triplets[i][1]);
                state[2] = max(state[2], triplets[i][2]);
            }
            if (state == target) {
                return true;
            }
        }
        return false;
    }
};
