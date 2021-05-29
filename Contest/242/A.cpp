class Solution {
public:
    bool checkZeroOnes(string s) {
        int a = 0, b = 0;
        for (int i = 0; i < s.size();) {
            if (s[i] == '1') {
                int j = i;
                while (j < s.size() && s[j] == '1') {
                    j++;
                }
                a = max(a, j - i);
                i = j;
            } else {
                int j = i;
                while (j < s.size() && s[j] == '0') {
                    j++;
                }
                b = max(b, j - i);
                i = j;
            }
        }
        return a > b ? true : false;
    }
};
