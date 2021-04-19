typedef long long LL;
class Solution {
public:
    // 时间复杂度：O(nlogk) 空间复杂度：O(n)
    // 利用multiset来存放对于当前nums[i]合法的元素
    // 注意大整数溢出的问题，需要开long long
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len = nums.size();
        if (len < 2) {
            return false;
        }
        multiset<LL> st;
        st.clear();
        for (int i = 0; i < len; i++) {
            if (i >= k + 1) {
                st.erase(st.find(nums[i-k-1]));
            }
            auto it = st.lower_bound(1l * nums[i] - t);
            if (it != st.end() && 1l * (*it) <= 1l * nums[i] + t) {
                return true;
            }
            st.insert(1l * nums[i]);
        }
        return false;
    }
};
