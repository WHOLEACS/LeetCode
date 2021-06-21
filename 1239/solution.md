#### 位运算 + dfs
* 要求字符串数组子序列形成的字符串中没有重复的元素，看数据发现数组长度为16，使用暴力搜索，对于数组中每个元素均有取或不取两种状态，故总状态为2^16，可以暴力求解
* 使用位运算加速判断和搜索速度，首先预处理arr字符串数组，如果发现字符串中本来就有重复的字母，那么这个字符串不能参与拼接，我们把每个字符串中每个字母的出现情况映射成一个二进制数，例如：ac -> (101), 字符串由26个字母组成，最多到2^26-1, 开int即可
```c++
for (int i = 0; i < arr.size(); i++) {
	int mask = 0;
	for (int j = 0; j < arr[i].size(); j++) {
		// 当前字符串有重复字母
		if ((mask >> (arr[i][j] - 'a')) & 1) {
			mask = 0;
			break;
		}
		// 把该位置置为1
		mask |= 1 << (arr[i][j] - 'a');
	}
	if (mask) {
		masks.emplace_back(mask);
	}
}
```
* 搜索过程：维护结果变量ans，将ans与上文得到的合法的字符串二进制数做与运算，如果结果为0,说明ans与当前字符串没有公共部分，可以填入，尝试填入，做下一步dfs；否则，不填入，指针移动，ans不发生变化
```c++
void dfs(int idx, const vector<int>& masks, int ans) {
	// 结束条件：idx移动到了masks末尾，此时看ans中1的数量，即是一个合法的各个字母不同的字符串，字符串长度就是ans中1的个数
	if (idx == masks.size()) {
		solve = max(solve, __builtin_popcount(ans));
		return;
	}
	if ((ans & masks[idx]) == 0) {
		// 可以填入
		dfs(idx + 1, masks, ans | masks[idx]);
	} 
	// 不填入
	dfs(idx + 1, masks, ans);
	return;
}
```
* 时间复杂度：O(sum(arr[i]) + 2^n) 空间复杂度：O(n) n == len(arr)
