typedef pair<int,int> PII;
class Solution {
public:
    //数组变成循环遍历  对数组进行两次遍历即可
	//单调栈 (从栈底到栈顶依次递减)
	vector<int> nextGreaterElements(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) return {};
		vector<int> solve(len, -1);
		stack<PII> st;
		while (!st.empty()) {
			st.pop();
		}
		for (int i = 0; i < len; i++) {
			if (st.empty() || nums[i] <= st.top().first) {
				st.push(make_pair(nums[i], i));
			} else {
				while (!st.empty() && nums[i] > st.top().first)
				{
					solve[st.top().second] = nums[i];
					st.pop();
				}
				st.push(make_pair(nums[i], i));
			}
		}
		for (int i = 0; i < len - 1; i++) {
			if (st.empty() || nums[i] <= st.top().first) {
				st.push(make_pair(nums[i], i));
			} else {
				while (!st.empty() && nums[i] > st.top().first)
				{
					solve[st.top().second] = nums[i];
					st.pop();
				}
				st.push(make_pair(nums[i], i));
			}
		}
		return solve;
    }
};
