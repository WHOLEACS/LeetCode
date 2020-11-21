class Solution {
public:
	//去除掉k位，剩下的要求达到最小值且不能有前导0
	//贪心法 + 单调栈 （单调递增栈，从栈底到栈顶依次递增）
    string removeKdigits(string num, int k) {
		int len = num.size();
		if (len == k) return "0";
		stack<char> st;
		while (!st.empty()) st.pop();
		int remove = 0, index = 0;
		while (index < len) {
			if (st.empty()) {
				st.push(num[index]);
			} else {
				while (!st.empty() && remove < k && num[index] < st.top()) {
					st.pop();
					remove++;
				}
				st.push(num[index]);
			}
			index++;
		}
		while (remove < k) {
			st.pop();
			remove++;
		}
		//去除前导0
		int flag = 0;
		string solve = "";
		while (!st.empty()) {
			solve += st.top();
			if (st.top() == '0') flag++;
			else flag = 0;
			st.pop();
		}
		reverse(solve.begin(), solve.end());
		return solve.substr(flag).size() == 0 ? "0" : solve.substr(flag);
    }
};
