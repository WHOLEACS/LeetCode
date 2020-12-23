class Solution {
private:
	int done[26];
public:
	Solution() {
		memset(done, 0, sizeof(done));
	}
    int firstUniqChar(string s) {
		int len = s.size();
		if (len == 0) return -1;
		for (int i = 0; i < len; i++) {
			done[s[i] - 'a']++;
		}
		for (int i = 0; i < len; i++) {
			if (done[s[i] - 'a'] == 1) return i;
		}
		return -1;
    }
};
