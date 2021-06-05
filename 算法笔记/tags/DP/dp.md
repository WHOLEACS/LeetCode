#### 要点
* 问题规模如何缩小
* 规模较小问题如何状态转移
* 子问题的最优解是否确定带来全局的最优解（通过举例论证），最优子结构是什么
* 动态规划
    * 状态定义
    * 状态转移
    * 边界case
    * return 哪个状态
* 方法
    * 打表 贪心找到近似解
---
#### 题目
* [LeetCode Contest 243 D](https://leetcode-cn.com/problems/minimum-skips-to-arrive-at-meeting-on-time/)
    * 状态定义：f\[i][j]表示前i段跳过j次的最短用时
    * 状态转移：讨论第i段是否跳过
    * 边界case：i=0 j=0 j=i j\>i的情况
    * return哪个状态：j表示跳过的次数，返回的是使f\[n][j]<=规定用时的最小j值
    * 精度问题
