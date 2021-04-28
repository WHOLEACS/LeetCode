#### 暴力枚举
* 枚举a从0到sqrt(c)即可
* 时间复杂度：O(sqrt(c)) 空间复杂度：O(1)
#### 双指针
* 把a置为0，把b置为sqrt(c)，我们想象整个搜索过程类似在二维矩阵中寻找c，那么此时我们在右上角，该矩阵元素为a\*a+b\*b，所以满足同一行从左到右递增，同一列从上到下递增，那么该问题即可转换成一道经典的编程题（在二维数组中找到目标值）
* 利用双指针，如果此时a\*a+b\*b == c, return true; 如果 a\*a+b\*b < c, 那么此时a++; 否则，b++
* 为什么[使用双指针不会错过最优解](https://leetcode-cn.com/problems/sum-of-square-numbers/solution/shuang-zhi-zhen-de-ben-zhi-er-wei-ju-zhe-ebn3/)
* 时间复杂度：O(sqrt(n)) 空间复杂度：O(1)
