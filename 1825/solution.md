#### 思维
* 使用队列queue存放当前的m个元素，设置三个multiset表示lower、middle、upper三个区间，在执行addElement操作时，维护三个multiset完成删除和新增操作，同时维护sum表示middle中元素的和
* 详情看[题解](https://leetcode-cn.com/problems/finding-mk-average/solution/c-san-ge-multiset-jian-dan-mo-ni-by-newh-y4q9/)
