class Solution {
private:
	int done[26];
public:
	Solution() {
		memset(done, 0, sizeof(done));
	}
    char findTheDifference(string s, string t) {
		int len_s = s.size(), len_t = t.size();
		if (len_s == 0) return t[0];
		for (int i = 0; i < len_s; i++) {
			done[s[i] - 'a']++;
		}
		for (int i = 0; i < len_t; i++) {
			done[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (done[i]) {
				return i + 'a';
			}
		}
		return 'a';
    }
};
