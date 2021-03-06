#### A
* 略，基础题
* 注意函数内套函数的写法
```c++
    auto find = [&](string& temp) {
        long long ans = 0;
        for (int i = 0; i < temp.size(); i++) {
            ans = ans * 10 + 1l * (temp - 'a');
        }
        return ans;
    };
```
* 时间复杂度：O(n) 空间复杂度：O(1)
#### B
* 贪心法
* 在十进制数中寻找位置插入x使得这个数最大化，那么如果是负数的时候，要使得数尽量小，而在正数的时候使得数尽可能大，正负不同，任务不同
* 在正数时要使得值尽可能大，那么需要在高位填入大数，即遍历字符串，找到x大于的第一个元素位置；在负数时，从1开始遍历，要使得数值尽可能小，找到x小于的第一个元素位置
* 利用string.insert(int pos, to\_string(x))在指定位置插入即可
* 时间复杂度：O(n) 空间复杂度：O(1)  n为原字符串长度
#### C
* 自定义优先队列
* 设置忙碌队列（根据服务器权重weight和下标进行堆排序）、空闲队列（存放任务完成时间和服务器下标，堆排序）和任务队列
* 注意任务的开始时间，每次从任务队列中弹出任务后，从忙碌队列中抽出空闲的服务器到空闲队列中，从空闲队列中分配服务给到当前作业任务
* 注意只有一台服务器的情况
* 时间复杂度：O(mlogm + n) 空间复杂度：O(m+n) m:服务器数量 n:任务数量
#### D
* 动态规划
    * 缩小问题规模
        * 讨论最后一段距离是跳过还是不跳过，那么问题规模-1,找到小规模的问题的解与大问题中最后一段距离的状态转移方式即可求解
    * 最优子结构，部分的最优解不一定带来全局的最优解
        * 子问题的最优跳过方案不一定是从全局角度看的最优跳过方案
* 状态定义
    * f\[i][j]表示前i段跳过j次后的最短耗时
* 状态转移
    * 以第i段是否跳过做讨论，如果第i段跳过，f\[i][j]=f\[i-1][j-1]+dist[i-1]/speed，否则，不跳过，f\[i][j]=ceil(f\[i-1][j]+dist[i-1]/speed), 因为不跳过时，最后一段要等待直到到达整点，所以要向上取整, f\[i][j]=min(f\[i-1][j-1]+dist[i-1]/speed, ceil(dp\[i-1][j]+dist[i-1]/speed))
* 边界case
    * j > i时，j超过过了此时的最大跳过次数，这个状态不合法
    * j = i时，j达到了最大的跳过次数，此时第i段只能选择跳过
    * j = 0时，此时f\[i][j]只能从不跳过转移而来
    * i = 0时，表示没有路可走，f\[i][j]=0
* return 结果
    * 得到的是最短耗时，从左到右遍历第n行，取第一个时间<=hoursBefore的列下标即是解
* 时间复杂度：O(nm) 空间复杂度：O(nm)
* [注]**精度问题**, 详见[题解](https://leetcode-cn.com/problems/minimum-skips-to-arrive-at-meeting-on-time/solution/minimum-skips-to-arrive-at-meeting-on-ti-dp7v/)
