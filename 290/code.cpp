class Solution {
private:
	unordered_map<string, string> mp;
	unordered_set<string> st;
public:
	Solution() {
		mp.clear();
		st.clear();
	}
	//建立映射
    bool wordPattern(string pattern, string s) {
		int len_s = s.size(), len_pattern = pattern.size();
		if (len_s == 0 || len_pattern == 0) return false;
		if (len_s < len_pattern) return false;
		s += ' ';
		len_s++;
		int space = 0, last = 0, ind = 0;
		while (last < len_s && ind < len_pattern) {
			while (space < len_s && s[space] != ' ') {
				space++;
			}
			string temp = s.substr(last, space - last);
			string pattern_now = pattern.substr(ind, 1);
			if (mp.find(pattern_now) == mp.end()) {
				if (st.find(temp) == st.end()) {
					mp[pattern_now] = temp;
					st.insert(temp);
				} else {
					return false;
				}
			} else {
				if (mp[pattern_now] != temp) return false; 
			}
			ind++;
			space++;
			last = space;
		}
		if (ind == len_pattern && last == len_s) return true;
		return false;
    }
};
