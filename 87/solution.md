#### 动态规划 记忆化dfs
* 定义状态 f(s1, s2)表示当前从s1到达s2是否可行
* 如果s1 == s2，那么得到f(s1, s2) = true，否则如果发现s1和s2长度不同或者两个字符串包含的字母种类或数量不同，那么可以断定f(s1, s2) = false (一些情况)
* 考虑状态转移，存在两种方式，交换或者不交换，详情见[题解](https://leetcode-cn.com/problems/scramble-string/solution/rao-luan-zi-fu-chuan-by-leetcode-solutio-8r9t/)
