#### A
* 思维题
* 统计每个字母出现的次数，如果存在一个字母，使得次数num%len(words)不为0,说明字母无法做到平均分配，返回false；否则，返回true
* 时间复杂度：O(sum(words[i].length)) 空间复杂度：O(1)
#### B
* 二分答案 + 双指针判断子串
* 提示
    * 字符串s中移除k+1个字符后，s就不是p的母串---意味着k是临界值，<=k时满足条件，而\>k时不满足条件，符合很明显的二分单调性
    * 判断一个串p是否为s的子序列（**不同于子串，子串使用暴力或者kmp来判断匹配**），可以使用双指针的方法，使用贪心策略尽可能的使匹配提前
    ```c++
   	// 利用哈希表来存放erase的位置
	vector<bool> vec(s.size(), true);
	for (int i = 0; i < k; i++) {
		vec[removable[i]] = false;
	}
	int idx_p = 0;
	for (int i = 0; i < s.size(); i++) {
		if (vec[i] && p[idx_p] == s[i]) {
			idx_p++;       
		}
	}
	return idx_p == p.size(); 
    ```
* 时间复杂度：O(mlogn) 空间复杂度：O(m) m == s.size() n == removable.size()
#### C
* 贪心
* 根据题意，我们要寻找一种方法使得target[i]=max(max(p(i), p(j)), max(f(i), f(j))), 其中p和f又分别表示其他元素取max后的结果
* 提示
    * 一个三元组只能被使用0次或1次，同时在达到最终结果的路径上，三元祖取max顺序可以交换
    * 对于任意一个三元组(ai,bi,ci)
        * 如果ai > target[0] or bi > target[1] or ci > target[2], 说明这个三元组不在路径中
        * 否则，一定有ai <= target[0] 并且 bi <= target[1] 并且 ci <= target[2]，由于所有的操作都是max操作，因此选择这个三元组不会使得结果变坏，不会使得原本得到target的某种选择变得不可行
* 思路与算法
    * 遍历三元组数组arr，如果当前元素arr[i]满足arr\[i][0] <= target[0] && arr\[i][1] <= target[1] && arr\[i][2] <= target[2], 对当前arr[i]取max，直到得到target或者返回false
* 时间复杂度：O(n) 空间复杂度：O(1) n == triplets.size()
