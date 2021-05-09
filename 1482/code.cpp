class Solution {
public:
    // 判断当前天数时候可以满足插花
    bool judge(const vector<int>& bloomDay, int& mid, int m, const int& k, const int& len) {
        for (int i = 0; i < len; i++) {
            if (bloomDay[i] <= mid) {
                int j = i;
                while (j < len && bloomDay[j] <= mid) {
                    j++;
                }
                int ans = j - i;
                m -= ans / k;
                if (m <= 0) {
                    return true;
                }
                i = j;
            }
        }
        return false;
    }

    // 时间复杂度：O(logmax(bloomDay) * len(bloomDay)) 空间复杂度：O(1)
    int minDays(vector<int>& bloomDay, int m, int k) {
        int len = bloomDay.size();
        if (len < m*k) {
            return -1;
        }
        int max_day = -0x3f3f3f3f;
        for (int& it : bloomDay) {
            max_day = max(max_day, it);
        }
        int l = 1, r = max_day + 1;
        // 二分答案
        while (l < r) {
            int mid = (l + r) >> 1;
            // 判断mid天后时候可以满足m束花
            bool flag = judge(bloomDay, mid, m, k, len);
            if (flag) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
