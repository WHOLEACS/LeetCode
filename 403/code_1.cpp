typedef pair<int, int> PII;
class Solution {
private:
    map<PII, int> mp;
public:
    // 记忆化搜索(画图找出重复的状态节点) + 二分
    // 状态：当前的位置 + 上一次走过的距离 (当前状态是否可以达到目标 0:未计算 1:可以达到 -1:不可达到)
    // 二分可能的位置上是否可行
    // 递归：返回值 调用单元 终止条件
    int dfs(int pos, int lastdis, const vector<int>& stones, const int& target) {
        if (pos > target) {
            return -1;
        }
        if (pos == target) {
            return mp[make_pair(pos, lastdis)] = 1;
        }
        if (mp.find(make_pair(pos, lastdis)) != mp.end() && mp[make_pair(pos, lastdis)] != 0) {
            return mp[make_pair(pos, lastdis)];
        }
        if (*lower_bound(stones.begin(), stones.end(), pos) != pos) {
            return mp[make_pair(pos, lastdis)] = -1;
        }
        for (int i = lastdis - 1; i <= lastdis + 1; i++) {
            if (pos + i <= pos || pos + i > target) {
                continue;
            }
            int temp = pos + i;
            if (dfs(temp, i, stones, target) == 1) {
                return mp[make_pair(pos, lastdis)] = 1;
            }
        }
        return mp[make_pair(pos, lastdis)] = -1;
    }

    bool canCross(vector<int>& stones) {
        int len = stones.size();
        if (stones[1] - stones[0] > 1) {
            return false;
        }
        return dfs(0, 0, stones, stones[len - 1]) == 1;
    }
};
