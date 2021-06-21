#### 要点
* 状态如何转移，有哪些变量
* 是否需要设置done数组标记已访问节点(避免重复访问造成无限递归)，是否需要回溯(已经访问过的状态节点是否需要多次访问，常常配合done数组出现，回溯时标记为false)
* 是否有重复节点，需要记忆化操作(常作为dp的递归形式)
---
#### 题目
* [LeetCode 1239](https://leetcode-cn.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/)
    * 对于每个节点有两个方向可走，每层递归找到数组的下一个下标所指的位置
    * 不需要设置done数组，有向图，不需要回溯
    * 由于每个节点有两个子节点，构成一棵满二叉树，节点总数为2^n-1
