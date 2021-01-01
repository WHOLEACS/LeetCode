###### 贪心法
----
* 通过冷静分析，我们发现，如果要使得尽可能少的去掉区间使得剩下的区间不重叠，等同于找到最长的一组区间，使得它们不重叠
* 把问题转换之后，通过对区间右端进行排序，思想就是结束的越早，那么这个区间就可能更长的得到衍生，最终得到最长不重合区间
* 时间复杂度：O(nlogn) 空间复杂度：O(1)