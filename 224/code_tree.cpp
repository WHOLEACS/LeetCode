class Solution {
private:
    struct TreeNode {
        string val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(string val) {
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
        }
        TreeNode(string val, TreeNode* left, TreeNode* right) {
            this->val = val;
            this->left = left;
            this->right = right;
        }
    };
public:
    // 递归：返回值 调用单元 终止条件
    TreeNode* create_Tree(const string& target, int left, int right) {
        TreeNode* root = nullptr;
        if (left > right) {
            return root;
        }
        // 判断当前target[left:right]是否全部是数字
        bool flag = true;
        for (int i = left; i <= right; i++) {
            if (!isdigit(target[i])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            root = new TreeNode(target.substr(left, right-left+1));
            return root;
        }
        // 找到当前根节点，优先级最低的运算符 如果运算符优先级相同，选择最右边的，因为同级运算满足从左向右的规则
        int p = 0;
        int c1 = -1, c2 = -1;
        for(int i = left; i <= right; i++)
        {
            switch(target[i])
            {
                case '(': p++; break;
                case ')': p--; break;
                case '+': case '-': if(!p) c1 = i; break;
                case '*': case '/': if(!p) c2 = i; break;
            }
        }
        if(c1 < 0) c1 = c2;		//找不到括号外的加减号，就用乘除号
        if(c1 < 0) return create_Tree(target, left+1, right-1);		//整个表达式被一对括号括起来
        root = new TreeNode(target.substr(c1, 1));
        root->left = create_Tree(target, left, c1-1); 
        root->right = create_Tree(target, c1+1, right);
        return root;
    }

    void post_order(vector<string>& vec, TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        post_order(vec, root->left);
        post_order(vec, root->right);
        vec.emplace_back(root->val);
    }

    int to_int(const string& target) {
        int ans = 0;
        for (int i = 0; i < target.size(); i++) {
            ans = ans * 10 + (target[i] - '0');
        }
        return ans;
    }

    // 表达式树+栈  中缀 -> 后缀
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
        len = s_n_n.size();
        // 构建表达式树
        TreeNode* root = create_Tree(s_n_n, 0, len - 1);
        vector<string> vec;
        vec.clear();
        // 后序遍历得到后缀表达式
        post_order(vec, root);
        // 后缀表达式计算
        stack<int> st;
        while (!st.empty()) {
            st.pop();
        }
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == "+" || vec[i] == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (vec[i] == "+") {
                    st.push(a+b);
                } else {
                    st.push(b-a);
                }
            } else {
                st.push(to_int(vec[i]));
            }
        }
        return st.top();
    }
};
