#### code3 一层循环 + 哈希表
* 连续区间的异或值，首先想到求前缀异或数组sum，sum[0]=0, sum[1]=arr[0], sum[2]=arr[0]^arr[1],...,sum[len]=arr[0]^arr[1]^...^arr[len-1], 所以给定连续区间[i,j], 其内异或运算得到的值为arr[i]^arr[i+1]^...^arr[j] = sum[i] ^ sum[j+1], 所以首先求出异或数组
* 目标是求这样的三元组{i,j,k}使得arr[i]^arr[i+1]^arr[i+2]^...^arr[j-1] = arr[j]^arr[j+1]^arr[j+2]^...^arr[k]，把原式用求得的异或数组表示，即sum[i]^sum[j]=sum[j]^sum[k+1], 等式两边同时去掉sum[j]，即sum[i] = sum[k+1], 当满足这个等于前提下，该位置k对于结果的贡献值为temp=k-i (因为i\<j<=k)
    1. 枚举i和k值，寻找相同的sum值，时间复杂度O(n^2) (code2)
    2. 进一步化简，如果我们只循环一次，当我们到达k位置时，想知道此时前面\<k的满足条件的i值有多少个，设数量为m，那么此时在k处的贡献值为ans=(k-i1)+(k-i2)+...+(k-im), 等式变换得ans=m\*k-(i1+i2+i3+...+im)，如果用哈希表来存放m值和满足条件的下标i的和值，那么在k处的查询复杂度就是O(1), 整体复杂度为O(n)
* 时间复杂度：O(n) 空间复杂度：O(n)
---
#### code2 双层循环
* 上述题解有解释
---
#### code1 哈希表
* 首先求出前缀异或表
* 枚举区间左值，把\<区间左值i，sum[i]^sum[j+1]> 作为key，把这个异或值出现的次数作为value，枚举所有可能的区间
* 双层循环，对于每个区间i和j（i\<j），在哈希表中查询\<区间左值为j，正在枚举得到的区间异或值>作为kay的value，并把它累加到结果solve中
* 时间复杂度：O(n^2\*logn)(n^2是双层枚举复杂度，logn是当前区间查询map复杂度) 时间复杂度：O(n)
> **这个题要格外注意下标的对应关系，分析清楚开闭区间在下标上的不同**<br>
> [参考题解](https://leetcode-cn.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/solution/xing-cheng-liang-ge-yi-huo-xiang-deng-sh-jud0/)
