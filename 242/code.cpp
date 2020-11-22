class Solution {
public:
	bool isAnagram(string s, string t) {
		int len_s = s.size(), len_t = t.size();
		if (len_s != len_t) return false;
		int done[26];
		memset(done, 0, sizeof(done));
		for (int i = 0; i < len_s; i++)
		{
			done[s[i]-'a']++;
		}
		for (int i = 0; i < len_s; i++)
		{
			done[t[i]-'a']--;
			if (done[t[i]-'a'] < 0) return false;
		}
		return true;
	}
};
