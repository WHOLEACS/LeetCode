#### 双指针
* 要求每个元素出现一次，最终返回一个len表示当前nums的长度
* 使用双指针left和right表示慢快指针下标，初始值设置成0和1,如果发现两个指针指向的元素不同，nums[left] != nums[right]，那么left右移，把right值赋给left，nums[++left] = nums[right]，left值指向上一个不重复的元素，right指向当前遍历的元素
* 最终返回left+1
* 时间复杂度：O(n) 空间复杂度：O(1)
