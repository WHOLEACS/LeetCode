class Solution {
public:
	//时间复杂度：O(n)	空间复杂度；O(1)
	//双指针
	vector<int> sortArrayByParityII(vector<int>& A) {
		int len = A.size();
		if (len <= 1) return A;
		//l指向奇偶，r指向偶奇
		int l = 0, r = 0;
		while (l < len && r < len)
		{
			while (l < len) {
				if ((l&1) && !(A[l]&1)) {
					break;
				}
				l++;
			}
			while (r < len) {
				if (!(r&1) && (A[r]&1)) {
					break;
				}
				r++;
			}
			if (l < len && r < len) swap(A[l], A[r]);
			l++, r++;
		}
		return A;
	}
};
