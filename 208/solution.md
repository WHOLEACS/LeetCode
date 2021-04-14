#### 字典树
---
* 0.字典树的数据结构
定义一个flag表示当前节点是否是一个单词的末尾节点，next数组存储着当前节点可以向何种方向延伸，代表着当前字母的下一个字母有可能是什么，初始都设置成空
```c++
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
```
* 1.插入新单词
dfs搜索当前单词，按照idx的顺序进行，如果当前idx到达单词len，把root的flag值设置成true。否则，寻找当前节点的next数组是否有指向word[idx]的指针，如果有，不需要重新new
```c++
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
```
* 2.检索word
do\_search函数做检索的任务，如果当前节点不存在或者idx到达单词结束位置后发现flag值为false，那么返回false
```c++
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
```
* 3.查找前缀
在检索函数中增加is\_search参数表明当前是search还是前缀查找，二者略有区别，前缀查找不需要精确匹配，详情见代码
