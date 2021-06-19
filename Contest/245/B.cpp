class Solution {
public:
    // 二分
    bool judge(int k, string s, string p, vector<int>& removable) {
        // 双指针
        // 利用哈希表来存放erase的位置
        vector<bool> vec(s.size(), true);
        for (int i = 0; i < k; i++) {
            vec[removable[i]] = false;
        }
        int idx_p = 0;
        for (int i = 0; i < s.size(); i++) {
            if (vec[i] && p[idx_p] == s[i]) {
                idx_p++;       
            }
        }
        return idx_p == p.size();
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0, r = removable.size() + 1;
        while (l < r - 1) {
            int mid =  l + ((r - l)/2);
            bool flag = judge(mid, s, p, removable);
            if (flag) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
