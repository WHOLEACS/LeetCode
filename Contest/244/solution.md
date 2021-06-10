#### A
* 略，基础题
* 注意方阵旋转时 横纵坐标的对应关系
* 时间复杂度：O(n^2) 空间复杂度：O(n^2)
#### B
* 题意要把所有数通过操作变成低一级的元素，直至数组中所有元素均相等
* 使用map存放每个数及其在数组中出现的次数，使用map的原因是不同等级的数有遍历的先后顺序
* 从map的最后一个等级开始向begin遍历，维护当前累加值即可
* 时间复杂度：O(nlogn) 空间复杂度：O(n) n为数组长度
#### C
* 经过两种类型转化后，要把原串s变成01交替出现的串，首先明确两种目标形态：01010...  10101..., 并使用如下代码构造t1 t2
```c++
    // 010
	string t1 = "0";
	for (int i = 1; i < s.size(); i++) {
		t1 += t1[i-1] == '0' ? '1' : '0';
	}
    // 101
	string t2 = "1";
	for (int i = 1; i < s.size(); i++) {
		t2 += t2[i-1] == '0' ? '1' : '0';
	}
```
* 如果s本身就是t1或t2，直接返回0；否则，观察操作1，把s的第一个字符添加到字符串的末尾，如：123 -> 231 -> 312, ***这个操作可以联想到两个s拼接***，即123123, 取长度为3的滑动窗口，我们依次得到123 231 312 123(重复), 而对于操作二，可以把s中的0换成1, 1换成0，求变成交替串要花费的最少的操作二次数
* 假设s = 10111001, T = s + s = 1011100110111001 在对T进行滑窗时，我们发现每次取len(s)=8个字符长度，而在第i个窗口转移到i+1个窗口时，***第i个窗口和第i+1个窗口内有len(s)-2=6个元素相等，所以应该使用O(1)的做法，找到两个相邻窗口的递推关系***；首先设置两个变量num\_t1(表示当前窗口内与t1串的距离，类似异或后求1的个数) num\_t2(表示当前窗口内与t2串的距离)，以T为例，初始时l=0, r=7, 窗口内容10111001, num\_t1= 5(01010101) num\_t2= 3(10101010), 滑动一个位置, l=1, r=8, 窗口内容01110011, 发现0111001这个子串是公共的，首先处理这个子串，维护num\_t1, 0111001 -> 0101010 (第一个窗口：0111001 -> 1010101)，***我们发现这个公共串在相邻窗口时对应的目标串的对应位置正好相反，那么意味着原来不一样的地方相同了，而原来相同的位置发生了变化，相邻窗口中公共的部分其与目标串的距离正好互补(num\_t = r - l + 1 - num\_t)***, 根据这个规律，得到以下代码
```c++
// 滑动窗口
int l = 0, r = s.size() - 1;
auto calc = [&](string& k1, string& k2) {
	int ans = 0;
	for (int i = 0; i < k1.size(); i++) {
		if (k1[i] != k2[i]) {
			ans++;
		}
	}
	return ans;
};
int num_t1, num_t2;
num_t1 = calc(s, t1);
num_t2 = calc(s, t2);
int solve = INT_MAX;
solve = min(solve, min(num_t1, num_t2));
while (r < T.size() - 1) {
	// 维护num_t1 num_t2
	num_t1 -= T[l] == t1[0] ? 0 : 1;
	num_t2 -= T[l] == t2[0] ? 0 : 1;
	l++;
	// 位置互补
	num_t1 = r - l + 1 - num_t1;
	num_t2 = r - l + 1 - num_t2;
	r++;
	num_t1 += T[r] == t1[t1.size() - 1] ? 0 : 1;
	num_t2 += T[r] == t2[t2.size() - 1] ? 0 : 1;
	solve = min(solve, min(num_t1, num_t2));
}
```
* 返回solve
* 时间复杂度：O(n) 空间复杂度：O(n) n = len(s)
#### D
* 暴力解法 TLE
    * 目的：浪费空间最小化
    * 思路：遍历箱子数组，对每个箱子进行排序，遍历背包，二分找到大于等于当前背包容量的且最小的箱子，使得浪费空间最低
    * 时间复杂度：O(m\*(nlogn + klogn)) 空间复杂度：O(n) m = len(boxes) n = len(boxes[i]) k = len(packages)
```c++
for (int i = 0; i < len_box; i++) {
	vector<int> temp = boxes[i];
	sort(temp.begin(), temp.end());
	if (temp[temp.size() - 1] < packages[len_pac - 1]) {
		continue;
	}
	LL k = 0;
	for (int j = 0; j < len_pac; j++) {
		k = (k + 1l * ((*lower_bound(temp.begin(), temp.end(), packages[j])) - packages[j]) % MOD) % MOD;
	}
	solve = min(solve, k);
}
```
* 前缀和 + 二分 + 双指针 AC
    * 暴力法复杂度过高，主要是mk两个for循环引发的
    * 题目中数据范围有明显提示 ***sum(boxes[j].length) <= 10^5***, 这意味着boxes中总箱子数量不超过10^5个！！！，根据这一点，我们从箱子的角度进行二分，而不是从背包的角度，这样的话，下面的代码，即使是两个for循环，其次数是<=10^5的
    ```c++
	for (int i = 0; i < len_box; i++) {
            vector<int> temp = boxes[i]; 
            sort(temp.begin(), temp.end());
			for (int& it : temp) {
			// 从箱子除法对package进行二分
		}
	}
    ```
	* 根据上面的分析，对背包进行排序，做前缀和，遍历箱子二分得到当前这个箱子所能涵盖的背包数量，使用数量\*箱子容量-背包前缀和就得到这个区间内背包的最小浪费空间，利用双指针继续迭代向后，直到所有的背包或者箱子被处理结束
    * 时间复杂度：O(mlogm+n(klogk+klogm)) 空间复杂度：O(m+n) m=packages.size() n=boxes.size() k=boxes[i].size()
    ```c++
	LL solve = LLONG_MAX;
	// 前缀和
    vector<LL> sum(len_pac + 1, 0);
	for (int i = 1; i < len_pac + 1; i++) {
		sum[i] = 1l * sum[i-1] + 1l * packages[i-1];
	}
	for (int i = 0; i < len_box; i++) {
		vector<int> temp = boxes[i]; 
		sort(temp.begin(), temp.end());
		if (temp[temp.size() - 1] < packages[len_pac - 1]) {
			continue;
		}
		LL k = 0;
        // 双指针
		int l = 0, r;
		for (int& it : temp) {
            // 二分
			r = upper_bound(packages.begin(), packages.end(), it) - packages.begin();
			if (r <= l) {
				continue;
			}
			k = (k + (1l * (1l * r - l) * it - 1l * sum[r] + sum[l]));
			l = r;
			if (l == packages.size()) {
				break;
			}
		}
		solve = min(solve, k);
	}
    ```
    * 注意本题不能在运算中途对MOD取模，可能对带来错误
        * 首先solve需要赋值一个足够大的数，在这里我们赋值solve=LLONG_MAX=9223372036854775807 \> 9*1e18
        * 不能在中途取模的原因是我们需要得到的不是取模后的最小值，而是最小值后再取模，二者有一些差别
            * eg：min[6,12] mod 7, 正确结果是6， 而我们直接按照取模后的值来取min，就会得到min(6, 5) = 5
