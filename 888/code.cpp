typedef long long LL;
class Solution {
public:
	int my_binary_search(const vector<int>& B, const int& target) {
		int l = 0, r = B.size();
		while (l < r) {
			int mid = (l + r) >> 1;
			if (B[mid] == target) {
				return mid;
			} else if (B[mid] > target) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		return l;
	}
	// 两个数组交换一个数，使得两个数组的加和相等
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		int len_A = A.size();
		int len_B = B.size();
		int sum_A = 0;
		int sum_B = 0;
		for (int i = 0; i < len_A; i++) {
			sum_A += A[i];
		}
		for (int i = 0; i < len_B; i++) {
			sum_B += B[i];
		}
		LL avg = (1l * sum_A + 1l * sum_B) >> 1;
		sort (B.begin(), B.end());
		vector<int> solve(2);
		for (int i = 0; i < len_A; i++) {
			int target = 1l * A[i] + (avg - sum_A);
			int pos = my_binary_search(B, target);
			if (pos < len_B && B[pos] == target) {
				solve[0] = A[i];
				solve[1] = B[pos];
				break;
			}
		}
		return solve;
    }
};
