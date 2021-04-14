class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        stack<int> st;
        while (!st.empty()) {
            st.pop();
        }
        int sign = 1;
        st.push(sign);
        int i = 0, res = 0;
        while (i < len) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            if (s[i] == '+') {
                sign = st.top();
                i++;
            }
            if (s[i] == '-') {
                sign = -st.top();
                i++;
            }
            if (s[i] == '(') {
                st.push(sign);
                i++;
            }
            if (s[i] == ')') {
                st.pop();
                i++;
            }
            long long num = 0;
            while (i < len && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            res += sign*num;
        }
        return res;
    }
};
