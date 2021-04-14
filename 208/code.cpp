class Trie {
private:
    struct Node{
        bool flag;
        Node* next[26];
        Node() {
            this->flag = false;
            for (int i = 0; i < 26; i++) {
                this->next[i] = nullptr;
            }
        }
    };
    Node* root;
public:
    /** Initialize your data structure here. */
    // 实现字典树
    Trie() {
        root = new Node();
    }
    
    void dfs(Node* root, const string& word, int idx) {
        if (idx == word.size()) {
            root->flag = true;
            return;
        }
        Node* temp = root->next[word[idx] - 'a'];
        if (temp == nullptr) {
            temp = new Node();
        }
        root->next[word[idx] - 'a'] = temp;
        dfs(temp, word, idx + 1);
    }

    bool do_search(Node* root, const string& word, int idx, const bool& is_search) {
        if (root == nullptr) {
            return false;
        }
        if (idx == word.size()) {
            if (is_search) {
                if (root->flag) {
                    return true;
                }
                return false;
            } else {
                return true;
            }
        }
        Node* temp = root->next[word[idx] - 'a'];
        return do_search(temp, word, idx + 1, is_search);
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word == "") {
            return;
        }
        dfs(root, word, 0);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        bool is_search = true;
        return do_search(root, word, 0, is_search);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        bool is_search = false;
        return do_search(root, prefix, 0, is_search);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
