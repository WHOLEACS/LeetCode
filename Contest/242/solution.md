#### A
* 略，双指针
#### B
* 二分答案，需要注意精度和二分上下界的问题，在最后一个dist时，不需要进行向上取整，直接加上就行，这是一个坑
#### C
* 动态规划
    1. 从前向后
        * 分析：观察到元素0的i位置的状态会影响到的点的位置为[i+minJump, i+maxJump]，所以根据这个思路做dp，事先可以处理好所有元素为0的点（离散化）, dp[i]表示当前i位置是否可达，如果dp[i]可达，就去更新[i+minJump, i+maxJump]的状态
        * TLE, [i+minJump, i+maxJump]这个区间在相邻的i上重复很多节点，即使做离散化，在极端情况下还是很耗费时间
        * 优化：1. 避免同个位置的状态被重复更新 2. 离散化，避免元素1的位置  
        * [code](https://leetcode-cn.com/submissions/detail/180012077/)
    2. 从后向前
        * 分析：由上述从前向后的分析得到每个下标为j的位置的状态由[j-maxJump, j-minJump]区间内状态决定，只要这个区间内有可达点，当前状态就标记为true；而且观察[j-maxJump, j-minJump]这个区间，当j向后移动时，该区间也是同样的移动，所以维护一个sum值表示可达当前位置的可达情况即可，每次移动一个位置，去掉不在区间内和加上区间新增的点
        * AC 时间复杂度：O(n) 空间复杂度：O(n)
        * [code](https://leetcode-cn.com/submissions/detail/180035841/)
        * 优化：离散化处理 时间复杂度：O(m) 空间复杂度：O(m) m为s中元素为0的个数
        ```c++
			vector<int> vec;
			vec.clear();
			for (int i = 0; i < len; i++) {
				if (s[i] == '0') {
					vec.emplace_back(i);
				}
			}
			int m = vec.size();
			vector<bool> dp(m, false);
			// [vec[i] - maxJump, vec[i] - minJump]
			// 左右指针
			int sum = 0, l = 0, r = 0;
			for (int i = 0; i < m; i++) {
				dp[i] = i == 0 || sum > 0 ? true : false;
				// 维护sum，下一个状态
				while (i + 1 < m && vec[i + 1] - maxJump > vec[l]) {
					sum -= dp[l];
					l++;
				}
				while (i + 1 < m && vec[i + 1] - minJump >= vec[r]) {
					sum += dp[r];
					r++;
				}
			} 
        ```
* 树状数组
* 离散化 + map
* 离散化 + 双端队列 deque
#### D
