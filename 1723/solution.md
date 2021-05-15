#### 优先队列求近似解 + 回溯搜索剪枝
* 如果直接进行搜索，我们发现max\_weight >= solve这个剪枝由于solve较大所以剪枝效果不明显，所以采用了首先用优先队列得到一个近似解的方法减小solve，提高剪枝收益
* 进行dfs回溯搜索，重点解释一下这段代码
```c++
    int k = bag.size(), temp;
    // 首先尝试分配给未工作的人，对于没有工作时间的人来说，分配无差别
    if (used < k) {
        bag[used] = jobs[idx];
        dfs(idx + 1, jobs, bag, max(max_weight, bag[used]), used + 1);
        bag[used] = 0;
    }
    // 然后尝试分配给已经工作的人，注意范围为[0,used)，未分配人的情况已经搜索过了，如果范围是[0,k)，那么就会有很多的无用情况产生
    // 随后再暴力尝试
    for (int i = 0; i < used; i++) {
        // 把idx号job放到i背包中
        temp = max_weight;
        bag[i] += jobs[idx];
        if (bag[i] > temp) {
            temp = bag[i];
        }
        if (temp < solve) {
            dfs(idx + 1, jobs, bag, temp, used);
        }
        bag[i] -= jobs[idx];
    }
```
&nbsp;&nbsp;对于递归树，我们需要改变搜索路径使得solve值快速缩小以降低搜索复杂度，传入了一个used变量表示当前状态下已经工作过的工人数量，优先分配工作给没有工作的工人（对于当前状态来说，没有工作过的人同等看待，没有其他维度的差别）；在尝试分配工作给没有工作的工人后，我们对\[0, used)这个区间内的已经工作过的工人进行尝试分配工作（要注意这里的区间不是整个工人集合，对全部工人进行尝试会造成重复搜索）,其余内容不再赘述
> [参考题解，搜索调参](https://leetcode-cn.com/problems/find-minimum-time-to-finish-all-jobs/solution/gong-shui-san-xie-yi-ti-shuang-jie-jian-4epdd/)
---
#### 状压dp
* 预处理sum数组：sum数组本质上表示任务只分配给一个人时的工作时间，实现看代码，\__builtin\_ctz(i)表示i使用二进制表示时末尾连续0的数量（注意该函数传入0时会发生错误），解读sum初始化代码
```c++
    // 预处理sum数组
    vector<int> sum(col, 0);
    for (int i = 1; i < (1 << n); i++) {
        int x = __builtin_ctz(i), y = i - (1 << x);
        sum[i] = sum[y] + jobs[x];
    }
```
&nbsp;&nbsp;总共状态有(1<\<n)个，对于for循环内的代码，举例说明，假如说我们现在求6(110)状态的工作时间，x=1，y=4(100)，sum[6] = sum[4] + jobs[1]
* 状态定义：dp\[i][j]表示分配到i人时，任务状态为j的最小的最大工作时间，我们这里使用了状态压缩的方式表达任务分配状态，比如说5(101)表示第1个工作和第3个工作处于已分配的状态，而第二个工作处于未分配状态，任务数最大值为12，所以共有2^12个任务分配状态
* 状态转移：填充dp\[i][j]，对于当前的任务分配状态j，我们需要枚举它的子状态，比如说j = 6(110), 我们需要枚举的子状态有 6(110) 4(100) 2(010)，即对于j中的二进制位为1的任务进行排列组合，使得每一个1位置都有成0的时候。（x-1从二进制角度就是把x的最后一个1变成0，同时把1后的0变成1，eg：8（1000）-\> 7(0111) 5（101）-\> 4(100)），令子状态为x，那么补集状态为j-x，同时取补集（表示在当前j状态下把补集任务分配给i工人，使用预处理好的sum数组），遍历取max值中的min值，具体见代码
```c++
    for (int i = 1; i < k; i++) {
        for (int j = 0; j < (1 << n); j++) {
            int minn = INT_MAX;
            for (int x = j; x; x = (x - 1)&j) {
                minn = min(minn, max(dp[i-1][x], sum[j-x]));
            }
            dp[i][j] = minn;
        }
    }
```
* 边界情况：dp\[0][j]表示只有一个工人做任务，此时是边界情况，直接用预处理好的sum数组初始化即可
```c++
    // 初始状态
    for (int i = 0; i < (1 << n); i++) {
        dp[0][i] = sum[i];
    }
```
* 时间复杂度：O(n\*(3^n)) 空间复杂度：O(n\*(2^n)) 具体分析见题解
> [参考题解，状压dp](https://leetcode-cn.com/problems/find-minimum-time-to-finish-all-jobs/solution/wan-cheng-suo-you-gong-zuo-de-zui-duan-s-hrhu/)
