#### multiset + 二分
* 使用multiset维护当前的k个元素集合，当i >= 下标k+1的时候，首先erase掉nums[i-k-1]的元素，保证了 abs(i-j) <= k这个条件
* 第二步，发现还有一个条件，abs(nums[i]-nums[j]) <= t, 翻译一下，得到两个不等式 nums[j] <= nums[i] + t , nums[j] >= nums[i] - t，目前已知nums[i]和t，需要求nums[j]是否存在，我们对multiset进行二分查找，具体用lower\_bound查找nums[i]-t的位置所指向的值，如果能够找到且这个值<=nums[i] + t成立，那么说明所有的不等式都得到满足，此时返回true即可
* 时间复杂度：O(nlogk) 空间复杂度：O(k)
> 需要注意的是，我们发现使用stl的lower\_bound和直接使用容器的lower\_bound除了使用方法不同之外，在时间性能方面还存在着巨大的差异
```c++
	// 使用容器的lower_bound做二分
	auto it = st.lower_bound(1l * nums[i] - t);
```
```c++
	// 使用STL的lower_bound做二分
	auto it = lower_bound(st.begin(), st.end(), 1l * nums[i] - t);
```
> 当使用第二种方法做二分的时候，返回TLE超时。
> 根据查阅资料，了解到使用STL的做法时，不支持容器的随机访问，所以时间性能不是O(logn)，具体请查阅[原因](https://blog.csdn.net/CZWin32768/article/details/51752267)
