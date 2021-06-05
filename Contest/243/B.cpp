class Solution {
public:
    // 对于正数和负数有着不同的任务
    string maxValue(string n, int x) {
        int len = n.size();
        int solve = len;
        if (n[0] == '-') {
            // -
            for (int i = 1; i < len; i++) {
                if ((n[i]-'0') > x) {
                    solve = i;
                    break;
                }                    
            }
        } else {
            // +
            for (int i = 0; i < len; i++) {
                if ((n[i]-'0') < x) {
                    solve = i;
                    break;
                }                    
            }
        }
        n.insert(solve, to_string(x));
        return n;
    }
};
