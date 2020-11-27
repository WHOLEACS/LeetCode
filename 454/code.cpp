class Solution {
private:	
	unordered_map<int,int> mp_1;
	unordered_map<int,int> mp_2;
public:
	Solution()
	{
		mp_1.clear();
		mp_2.clear();
	}
	//哈希表映射
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int len_A = A.size(), len_B = B.size(), len_C = C.size(), len_D = D.size();
		for (int i = 0; i < len_A; i++)
		{
			for (int j = 0; j < len_B; j++)
			{
				mp_1[A[i] + B[j]] += 1; 
			}
		}
		for (int i = 0; i < len_C; i++)
		{
			for (int j = 0; j < len_D; j++)
			{
				mp_2[C[i] + D[j]] += 1;
			}
		}
		int solve = 0;
		for (auto it = mp_1.begin(); it != mp_1.end(); it++)
		{
			if (mp_2.find(-((*it).first)) != mp_2.end()) {
				solve += (*it).second * ((mp_2.find(-(*it).first))->second);
			}
 		}
		return solve;
    }
};
