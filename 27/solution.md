#### 双指针
* 设置两个指针，分别指向当前idx(去除val后的新数组下标)和原来数组的下标i，使用for循环遍历原来的nums数组
* 当遍历i发现当前nums[i]不是val时，nums[idx++] = nums[i]进行复制即可
* 时间复杂度：O(n) 空间复杂度：O(1)