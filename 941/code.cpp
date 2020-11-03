class Solution {
public:
	//判断给定的数组是否是山脉数组
    bool validMountainArray(vector<int>& A) {
		size_t len = A.size();
		if (len <= 2) return false;
		if(A[0] >= A[1]) return false;
		bool flag = true;
		for (int i = 0; i < len - 1; i++)
		{
			if (A[i] > A[i+1] && flag) {
				flag = false;
			}
			if ((A[i] >= A[i+1] && flag) || (A[i] <= A[i+1] && !flag)) return false;
		}
		if(flag) return false;
		return true;
    }
};
