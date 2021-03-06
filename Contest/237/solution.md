#### 1832 简单模拟
* 哈希表 (时间复杂度：O(n) 空间复杂度：O(n)) 排序后遍历 (时间复杂度：O(nlogn) 空间复杂度：O(1))
---
#### 1833 贪心
* 首先按照cost列表从小到大排列，目的是尽可能的满足cost，达到最大的满足数量
* 时间复杂度：O(nlogn) 空间复杂度：O(1)
---
#### 1834 map + 自定义优先队列
* 根据题意，cpu会选择当前任务队列中耗时最短的任务执行，如果有多个任务耗时相同，选择下标最小的。并且cpu在切换任务时没有耗时
* 自定义struct结构，time表示当前任务耗时，idx表示当前任务的下标，重载operator符号
* 使用map存放当前开始时间对应的vector数组（数组中存放的是当前任务在tasks中的下标）
* 进行模拟即可
* 时间复杂度：O(nlogn) 空间复杂度：O(n)
> [注意] 有可能存在一个任务执行完之后，下一个任务还没有开始的状态（此时队列为空，但是tasks任务列表没有执行完毕），这种情况下需要重新设置当前时间，比赛时在这个地方wa很多次，特别坑
---
#### 1835 数学
* 给定两个列表arr1和arr2，设i指向arr1，设j指向arr2，对于每个i，我们需要遍历arr2得到arr1[i]&arr2[j]，并最终生成一个大的列表arr，遍历arr，得到所有元素异或的结果
* 思路
    * 暴力 时间复杂度：O(n^2) TLE
    * 数学 最主要的是用了一个公式 (a&c) ^ (b&c) = (a^b)&c，关于证明，使用位运算。已知c中的每一个数位要么是0，要么是1，我们分类讨论。如果c中的某一位是0, a&c = a&0 = 0, b&c = b&0 = 0, 此时0^0 = 0, 看等式右侧，(a^b)&c = (a^b)&0 = 0; 如果c中的某一位是1，a&c = a&1 = a, b&c = b&1 = b, 等式左边为a^b, 观察等式右侧，(a^b)&c = (a^b)&1 = a^b, 等式左右等价，证毕
    * 对两个列表分别求异或的值x和y，最后作x&y即可
    * 时间复杂度：O(n) 空间复杂度：O(1)
