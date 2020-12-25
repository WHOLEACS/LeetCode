class Solution {
public:
	//双指针
    int findContentChildren(vector<int>& g, vector<int>& s) {
		int len_g = g.size(), len_s = s.size();
		if (len_g == 0 || len_s == 0) return 0;
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int ind_g = 0, ind_s = 0;
		while (ind_g < len_g && ind_s < len_s) {
			if (g[ind_g] <= s[ind_s]) {
				ind_g++;
			}
			ind_s++;
		}
		return ind_g;
    }
};
