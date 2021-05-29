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
    * 分析：每次查询[i-maxJump, i-minJump]这个区间，并把当前状态更新到树状数组上, 树状数组注意左右区间的开闭，同时看到一种优美的写法，函数嵌套到主函数内，参考下面这个find的写法
    ```c++
	// 树状数组查询操作, 查询[left, right]区间内是否存在可达点
    // 注意查询区间的开闭关系
    bool query(int left, int right) {
        left = max(left, 0);
        right++;
        int ans_l = 0, ans_r = 0;
        auto find = [&](int idx, int& ans) {
            while (idx) {
                ans += Tree[idx];
                idx -= lowbit(idx);
            }
        };
        find(left, ans_l);
        find(right, ans_r);
        return ans_r - ans_l > 0;
    }
    ```
    * AC 时间复杂度：O(nlogn) 空间复杂度：O(n)
    * [code](https://leetcode-cn.com/submissions/detail/180739743/)
* 离散化 + map
    * 分析：该方法是动态规划中从前向后方法的优化，进行了离散化，同时对于已经访问过的可达节点即使erase删除，避免了重复访问
    * 根据实验，vector内部数据依次存放，而map和set内元素是分散的
    * 从前向后更新，如果当前状态可达，[i+minJump, i+maxJump]利用map.lower\_bound和map.upper\_bound二分map，找到当前区间对应下标，更新can\_reach数组，并且删除可达位置
    * AC 时间复杂度：O(mlogm) 空间复杂度：O(m)
    ```c++
		map<int, int> mp;
        int m = vec.size();
        for (int i = 0; i < m; i++) {
            mp[vec[i]] = i;
        }
        // 从前向后更新
        vector<bool> can_reach(m, false);
        can_reach[0] = true;
        for (int i = 0; i < m; i++) {
            if (can_reach[i]) {
                for (auto be = mp.lower_bound(vec[i] + minJump); be != mp.upper_bound(vec[i] + maxJump);) {
                    can_reach[(*be).second] = true;
                    // 删除当前可达点，避免重复访问 
					auto next = be;
                    next++;
                    mp.erase(be);
                    be = next;
                }
            }
        }
    ```
    * [code](https://leetcode-cn.com/submissions/detail/180753806/)
* 离散化 + 双端队列 deque
    * 分析：和从后向前的动态规划方法差不多，只不过用队列维护了离散化后的状态和sum
    * 使用了deque双端队列，pop\_back() emplace\_back() pop\_front() emplace\_front()
    * 关键代码
    ```c++
		int ptr = 0;
        for (int i = 1; i < m; i++) {
            while (ptr < m && vec[ptr] + minJump <= vec[i]) {
                if (can_reach[ptr]) {
                    dq.emplace_back(vec[ptr]);
                }
                ptr++;
            }
            while (!dq.empty() && dq.front() < vec[i] - maxJump) {
                dq.pop_front();
            }
            can_reach[i] = !dq.empty();
        }
    ```
	* AC 时间复杂度：O(m) 空间复杂度：O(m)
	* [code](https://leetcode-cn.com/submissions/detail/180905414/)
#### D
* 前缀和 + 博弈思想动态规划
    * 分析
        * 每个人取完后都要把和放到左侧，这意味着前缀和保持不变，在任意一个人操作后，剩余所有石子的价值总和不会改变
        * 前缀和保持不变，等价于我们可以把问题等价转换成在前缀和数组中执行操作，每次从左侧取大于1个，意味着至少从1开始拿；当上一个人取到u时，下一个人只能从[u+1,n)这个区间取值
        * 状态定义：dp[i]表示Alice可以选择的下标u在[i,n)时，Alice和Bob的分数的最大差值
        * 状态转移：以Alice是否选择了下标i做讨论
            * 如果Alice不选择i，那么dp[i]=dp[i+1]
            * 否则，Alice选择了i，此时取到了前缀和pre_sum[i], 在[i+1,n)内是Bob**先手**(注意这里先后手的转换)拿到的最大差值f[i+1], 那么设Alice在[i,n)内分数为A，Bob在[i+1,n)内分数为B，即f[i+1]=B-A, 这样dp[i](Alice先手)=pre[i]+(A-B)=pre[i]-(B-A)=pre[i]-f[i+1]
        * 初始状态
            * dp[len-1] = pre_sum[i-1]
            * 最后答案是dp[1], 只是因为dp[0]是不存在的，我们每次取至少要拿大于一个
    * AC 时间复杂度：O(n) 空间复杂度：O(n)
    * 关键代码
    ```c++
    pre[0] = stones[0];
    for (int i = 1; i < len; i++) {
        pre[i] = pre[i-1] + stones[i];
    }
    dp[len - 1] = pre[len - 1];
    for (int i = len - 2; i >= 1; i--) {
        dp[i] = max(dp[i+1], pre[i] - dp[i+1]);
    }
    return dp[1];
    ```
    * [code](https://leetcode-cn.com/submissions/detail/181828260/)
> [官方题解](https://leetcode-cn.com/problems/stone-game-viii/solution/shi-zi-you-xi-viii-by-leetcode-solution-e8dx/)
