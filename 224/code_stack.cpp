class Solution {
public:
    int to_int(const string& target) {
        int ans = 0;
        for (int i = 0; i < target.size(); i++) {
            ans = ans * 10 + (target[i] - '0');
        }
        return ans;
    }

    // 栈 中缀转后缀
    int calculate(string s) {
        int len = s.size();
        string s_n = "";
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                continue;
            }
            s_n += s[i];
        }
        string s_n_n = "";
        for (int i = 0; i < s_n.size(); i++) {
            if (s_n[i] == '+' || s_n[i] == '-') {
                if (i == 0 || (!isdigit(s_n[i-1]) && s_n[i-1] != ')')) {
                    s_n_n += '0';
                }
            }
            s_n_n += s_n[i];
        }
        //cout << s_n_n << endl;
        len = s_n_n.size();
        vector<string> postfix;
        postfix.clear();
        stack<char> st;
        while (!st.empty()) {
            st.pop();
        }
        for (int i = 0; i < len; i++) {
            if (s_n_n[i] == '(') {
                st.push(s_n_n[i]);
                continue;
            }
            if (s_n_n[i] == ')') {
                while (st.top() != '(') {
                    postfix.emplace_back(string(1, st.top()));
                    st.pop();
                }
                st.pop();
                continue;
            }
            if (isdigit(s_n_n[i])) {
                int temp = i;
                while (temp < len && isdigit(s_n_n[temp])) {
                    temp++;
                }
                postfix.emplace_back(s_n_n.substr(i, temp - i));
                i = temp - 1;
                continue;
            }
            if (s_n_n[i] == '+' || s_n_n[i] == '-') {
                while (!st.empty() && st.top() != '(') {
                    postfix.emplace_back(string(1, st.top()));
                    st.pop();
                }
                st.push(s_n_n[i]);
            }
        }
        while (!st.empty()) {
            postfix.emplace_back(string(1, st.top()));
            st.pop();
        }
        // 后缀表达式求值
        stack<int> st_n;
        while (!st_n.empty()) {
            st_n.pop();
        }
        for (int i = 0; i < postfix.size(); i++) {
            if (postfix[i] == "+") {
                int right = st_n.top();
                st_n.pop();
                int left = st_n.top();
                st_n.pop();
                st_n.push(left + right); 
            } else if (postfix[i] == "-") {
                int right = st_n.top();
                st_n.pop();
                int left = st_n.top();
                st_n.pop();
                st_n.push(left - right);
            } else {
                st_n.push(to_int(postfix[i]));
            }
        }
        return st_n.top();
    }
};
