class Solution {
public:
    // 栈 时间复杂度：O(n) 空间复杂度：O(n)
    string reverseParentheses(string s) {
        int len = s.size();
        stack<string> st;
        while (!st.empty()) {
            st.pop();
        }
        for (int i = 0; i < len;) {
            if (s[i] == '(') {
                st.push(string(1, '('));
                i++;
            } else if (s[i] == ')') {
                string temp = "";
                while (!st.empty() && st.top() != "(") {
                    string k = st.top();
                    reverse(k.begin(), k.end());
                    temp += k;
                    st.pop();
                }
                st.pop();
                if (temp != "") {
                    st.push(temp);
                }
                i++;
            } else {
                int j = i;
                while (j < len && isalpha(s[j])) {
                    j++;
                }
                st.push(s.substr(i, j - i));
                i = j;
            }
        }
        s = "";
        while (!st.empty()) {
            // string 的插入方法，在下标0前插入string串st.top()
            s.insert(0, st.top());
            st.pop();
        }
        return s;
    }
};
