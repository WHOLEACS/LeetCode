class Solution {
public:
	//时间复杂度：O(n) 空间复杂度：O(1)
    bool lemonadeChange(vector<int>& bills) {
		int len = bills.size();
		if (len == 0) return true;
		vector<int> vec(3, 0);
		for (int i = 0; i < len; i++) {
			if (bills[i] == 5) {
				vec[0]++;
			} else if (bills[i] == 10) {
				vec[0]--;
				if (vec[0] < 0) return false;
				vec[1]++;
			} else {
				if (vec[1] > 0 && vec[0] > 0) {
					vec[1]--, vec[0]--;
				} else if (vec[0] >= 3) {
					vec[0] -= 3;
				} else {
					return false;
				}
				vec[2]++;
			}
		}
		return true;
    }
};
