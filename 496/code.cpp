class Solution {
private:
    unordered_map<int, int> mp;
public:
    Solution() {
        mp.clear();
    }
    //哈希表 + 单调栈(由栈底到栈顶依次递减)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums1.size(); i++) {
            mp[nums1[i]] = i;
        }
        stack<int> st;
        while (!st.empty()) {
            st.pop();
        }
        vector<int> solve(nums1.size(), -1);
        int len = nums2.size();
        for (int i = 0; i < len; i++)
        {
            if (st.empty() || nums2[i] <= st.top()) {
                st.push(nums2[i]);
            } else {
                while (!st.empty() && nums2[i] > st.top()) {
                   int index = mp.find(st.top()) == mp.end() ? -1 : mp[st.top()];
                   if (index != -1) {
                       solve[index] = nums2[i];
                   }
                   st.pop();
                }
                st.push(nums2[i]);
            }
        }
        return solve;
    }
};
