class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int sum = 0;
        vector<int> vec(26, 0);
        for (int i = 0; i < words.size(); i++) {
            sum += words[i].size();
            for (int j = 0; j < words[i].size(); j++) {
                vec[words[i][j]-'a']++;
            }
        }
        int len = words.size();
        if (sum % len) {
            return false;
        }
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] % len) {
                return false;
            }
        }
        return true;
    }
};
