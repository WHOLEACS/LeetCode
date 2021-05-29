const double eps = 0.000001;
const int max_v = 10000000;
class Solution {
public:
    bool judge(int mid, vector<int>& dist, double hour) {
        double ans = 0;
        for (int i = 0; i < dist.size(); i++) {
            double temp = dist[i] / (double) mid;
            if (i != dist.size() - 1) {
                // 注意区分ceil和round的用法，ceil是数轴上的向上取整，而round只是说转到最近的整数
                temp = ceil(temp);
            }
            ans += temp;
        }
        return ans <= hour;
    }
    
    // 优化二分上界
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int len = dist.size();
        if ((double)(len - 1) - hour >= eps) {
            return -1;
        }
        int V = 0;
        for (int& distance : dist) {
            V = max(V, distance * 100);
        }
        V = min(V, max_v);
        int l = 1, r = V;
        while (l < r) {
            int mid = (l + r) >> 1;
            // 判断mid是否满足要求
            if (judge(mid, dist, hour)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }   
        return l;
    }
};
