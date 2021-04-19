class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> flag(26, false);
        for (auto it : sentence) {
            flag[it-'a'] = true;
        }
        for (int i = 0; i < 26; i++) {
            if (!flag[i]) {
                return false;
            }
        }
        return true;
    }
};
