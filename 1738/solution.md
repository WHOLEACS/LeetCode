#### 动态规划 + 优先队列（小顶堆）
* 求第k大：小顶堆  求第k小：大顶堆
* 容易想到使用动态规划，dp\[i][j]表示横坐标\<=i，纵坐标\<=j的元素matrix\[i][j]异或的结果
* 状态转移：dp\[i][j] = dp\[i-1][j] ^ dp\[i][j-1] ^ dp\[i-1][j-1] ^ matrix\[i][j]
* 边界情况：i = 0时，dp\[i][j]只能从左侧转移而来，j = 0时，dp\[i][j]只能由上侧转移而来，而当i=0 && j=0时，dp\[i][j] = matrix\[0][0]
* 空间优化：看到当前状态只和上一行有关，所以可以优化到一维dp数组，详细见代码，north\_west变量
```c++
    for (int j = 0; j < col; j++) {
        int temp = dp[j];
        if (i == 0 && j == 0) {
            dp[0] = matrix[0][0];
        } else if (i == 0) {
            dp[j] = dp[j-1] ^ matrix[i][j];
        } else if (j == 0) {
            dp[j] = dp[j] ^ matrix[i][j];
        } else {
            // 需要预存西北角
            dp[j] = north_west ^ dp[j-1] ^ dp[j] ^ matrix[i][j];
        }
        if (pq.size() < k) {
            pq.push(dp[j]);
        } else {
            if (dp[j] > pq.top()) {
                pq.pop();
                pq.push(dp[j]);
            }
        }
        north_west = temp; 
```
* 时间复杂度：O(m\*n\*logk) 空间复杂度：O(n)
