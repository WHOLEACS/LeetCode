class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
		int len = arr.size();
		if(len==1) return true;
		unordered_map<int,int> mp;
		mp.clear();
		for(int i=0;i<len;i++)
		{
			mp[arr[i]] += 1;
		}
		unordered_set<int> st;
		st.clear();
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			if(st.find(it->second) != st.end()) return false;
			st.insert(it->second);
		}
		return true;
    }
};
