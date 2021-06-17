class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int sum = 0, len = words.size();
        vector<int> vec(26, 0);
        for (int i = 0; i < len; i++) {
            sum += words[i].size();
            for (char& ch : words[i]) {
                vec[ch-'a']++;
            }
        }
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
