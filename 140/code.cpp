class Solution {
private:
    struct Node{
        bool flag;
        Node* next[26];
        Node() {
            flag = false;
            for(int i = 0; i < 26; i++)
            {
                next[i] = nullptr;
            }            
        }
    };
    vector<string> solve;
    Node* root;
    unordered_map<int,vector<string>> mp;
    vector<bool> is_calc;
public:
    Solution()
    {
        solve.clear();
        root = new Node();
        mp.clear();
        is_calc.clear();
    }
    //递归：返回值 调用单元 终止条件
    void construct_tree(Node* now_root, const string& str, int index)
    {
        if(index == str.size()) {
            now_root->flag = true;
            return;
        }
        Node* next_node = now_root->next[str[index]-'a'];
        if(next_node == nullptr) {
            next_node = new Node();
        }
        now_root->next[str[index]-'a'] = next_node;
        construct_tree(next_node, str, index+1);
    }
    //index为当前起始要进行查找的位置
    //递归：返回值 调用单元 终止条件
    void dfs(const string& s, Node* now_root, int index, string& now_str)
    {
        if(index == s.size() || now_root->next[s[index]-'a'] == nullptr) {
            if(index == s.size()) {
                now_str.pop_back();
                solve.push_back(now_str);
            }
            return;
        }
        if(is_calc[index]) {
            for(int i = 0; i < mp[index].size(); i++)
            {
                solve.push_back(now_str + mp[index][i]);
            }
            return;
        }
        Node* root = now_root;
        int index_right = index;
        while(index_right < s.size() && root->next[s[index_right]-'a'] != nullptr) {
            if(root->flag) {
                int len = now_str.size();
                now_str += s.substr(index, index_right-index);
                now_str += " ";
                dfs(s, now_root, index_right, now_str);
                string temp = s.substr(index, index_right - index);
                if(index_right == s.size()) {
                    mp[index].push_back(temp);
                }
                else {
                    for(int i = 0; i < mp[index_right].size(); i++)
                    {
                        mp[index].push_back(temp + " " + mp[index_right][i]);
                    }
                }
                now_str = now_str.substr(0, len);
            }
            root = root->next[s[index_right]-'a'];
            index_right++;
        }
        if(root->flag) {
            int len = now_str.size();
            now_str += s.substr(index, index_right-index);
            now_str += " ";
            dfs(s, now_root, index_right, now_str);
            string temp = s.substr(index, index_right - index);
            if(index_right == s.size()) {
                mp[index].push_back(temp);
            }
            else {
                for(int i = 0; i < mp[index_right].size(); i++)
                {
                    mp[index].push_back(temp + " " + mp[index_right][i]);
                }
            }
            now_str = now_str.substr(0, len);
        }
        is_calc[index] = true;
        return;
    }
    //记忆化搜索+字典树
    //首先根据字典构建字典树，然后进行递归搜索
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len = wordDict.size();
        if(len == 0) return {};
        for(int i = 0; i < len; i++)
        {
            construct_tree(root, wordDict[i], 0);
        }
        is_calc.resize(s.size(),false);
        string now_str = "";
        dfs(s, root, 0, now_str);
        return solve;
    }
};
