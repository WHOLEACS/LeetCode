#### A
* 编码题，略
* 时间复杂度：O(n) 空间复杂度：O(1) n == num.size()
#### B
* 思维题 + 细节
* 因为周期是15分钟，单位是分，所以首先把表示时间的字符串用分钟表示出来，需要注意的是如果第二天的时间小于第一天，说明通宵，需要把基准调整到前一天，所以加上一天
```c++
int hour1 = (startTime[0] - '0') * 10 + (startTime[1] - '0') * 1;
int min1 = (startTime[3] - '0') * 10 + (startTime[4] - '0') * 1;
int hour2 = (finishTime[0] - '0') * 10 + (finishTime[1] - '0') * 1;
int min2 = (finishTime[3] - '0') * 10 + (finishTime[4] - '0') * 1;
int time_1 = hour1 * 60 + min 1;
int time_2 = hour2 * 60 + min2;
if (time_2 < time_1) {
	time_2 += day;
}
```
* 利用两个time计算当前轮次，相减即可。**注意如果time不是从一个整点开始，那么时间开始一段不能算进去**
* 坑：**有可能开始时间和结束时间处于一个周期内，这时如果不做判断，会输出-1**
```c++
int num1 = time_1 / 15;
int num2 = time_2 / 15;
int solve = num2 - num1 - (time_1 % 15 == 0 ? 0 : 1);
return solve > 0 ? solve : 0;
```
* 时间复杂度：O(1) 空间复杂度：O(1) 
#### C
* 并查集 + dfs
* 预处理grid1，得到并查集parent数组，使用二维数组表示每个位置对应的森林，使得每个有1的岛屿都可以找到一个森林表示一个相连的大岛屿
* dfs遍历grid2，同时需要用done数组标记已经遍历过的陆地，避免重复访问；遍历过程中查询grid2中相连岛屿在grid1中是否也是同一个parent
* 时间复杂度：O(mnlog\*n) 空间复杂度：O(mn) m : len(grid) n : len(grid[0])
* 并查集的时间复杂度比O(logn)要快，近似等于O(1)，比O(1)慢一点
#### D
* 思维 + 哈希表 + 前缀和
* 每个query会指定一个区间，我们要找到这个区间内差值最小的不同的两个数，假设两个数的下标分别是i，j，对应的数是nums[i], nums[j], 求的是abs(nums[i]-nums[j])
* 如果暴力解答，对于每个query，复杂度为O(n^2), 因而整体复杂度为O(n^3), 不能通过本题
* 通过观察，我们发现1 <= nums[i] <= 100，这也就是说query得到的值只可能在[1, 99]之间（0不合法，我们要求两个数不相等）
    * 根据上述提示，我们需要快速得到每个query下区间内的[1, 100]的出现情况，不难想到使用前缀和的思想，eg：对于nums[i] = 1, sum[i] = 5(前i个出现过5个1)，sum[j] = 10(前j个出现过10个1)，使用sum[j]-sum[i]，就是当前所求区间内1的出现次数，随后遍历nums[i]的可能取值，找到最小差值，时间复杂度：O(1)
```c++
int query = queries.size();
vector<int> solve(query);
for (int i = 0; i < query; i++) {
	int l = queries[i][0], r = queries[i][1];
	vector<int> pre = sum[l];
	vector<int> after = sum[r+1];
	int temp = -1, p;
	for (int j = 1; j <= 100; j++) {
		if (after[j] - pre[j] > 0) {
			if (temp == -1) {
				temp = 0x3f3f3f3f;
			} else {
				temp = min(temp, j - p);
			}
			p = j;
		}
	}
	solve[i] = temp == 0x3f3f3f3f ? -1 : temp;
}
```
	* 预处理打表, 在每个位置做一个哈希表，表示到当前下标处累积的[1,100]内每个数出现的次数
    ```c++
	int len = nums.size();
	vector<vector<int>> sum(len + 1, vector<int>(105, 0));
	for (int i = 1; i < len + 1; i++) {
		sum[i] = sum[i-1];
		sum[i][nums[i-1]] += 1;
	}
    ```
