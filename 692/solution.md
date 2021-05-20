#### 哈希表 + 自定义优先队列
* 首先得到每个单词所对应的出现次数，使用哈希表进行存储，unordered\_map无序map，复杂度：O(n)
* 要得到出现次数最多的k个单词，可以使用小顶堆，自定义struct结构体，num表示单词出现次数，str表示单词内容，需要注意运算符重载，当num不同时，小num需要优先放到堆顶进行更换，而当num值相等时，优先把字典序较大的放到上边，因为题目规定字典序较小的优先
```c++
	struct node{
		int num;
		string str;
		node() {
			this->num = 0;
			this->str = "";
		}
		node(int num, string str) {
			this->num = num;
			this->str = str;
		}
		friend bool operator < (const node& a, const node& b) {
			return a.num != b.num ? a.num > b.num : a.str < b.str;
		}
	};
```
* 遍历map，如果当前队列size小于k，那么直接入队；否则，首先比较单词出现次数，如果pq.top()次数较小，那么堆顶出队，**而当单词出现次数相同时，比较字典序 (注意这个相等的条件，需要额外加一个pq.top().num == (it).second)**，如果pq.top()字典序较大，堆顶出队
```c++
	if (pq.size() < k) {
		pq.push(node((*it).second, (*it).first));
	} else {
		if (pq.top().num < (*it).second || (pq.top().num == (*it).second && pq.top().str > (*it).first)) {
			pq.pop();
			pq.push(node((*it).second, (*it).first));
		}
	}
```
* 遍历队列，把队列中的单词emplace\_back到solve容器中，用reverse做solve容器的翻转
* 时间复杂度：O(nlogk) 空间复杂度：O(n)
