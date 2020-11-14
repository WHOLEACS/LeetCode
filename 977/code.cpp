class Solution {
public:
	//双指针
    vector<int> sortedSquares(vector<int>& A) {
		int len = A.size();
		if(len==0) return {};
		vector<int> solve(len,0);
		int l = 0 , r = len-1;
		int index = len-1;
		while(l<r)
		{
			if(A[l]*A[l] < A[r]*A[r]) {
				solve[index--] = A[r]*A[r];
				r--;
			}
			else {
				solve[index--] = A[l]*A[l];
				l++;
			}
		}
		solve[0] = A[l] * A[l];
		return solve;
    }
};	
