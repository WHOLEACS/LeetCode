const int maxn = 5e6 + 5;
class Solution {
private:
	bool done[maxn];
public:
	Solution() {
		memset(done, true, sizeof(done));
	}
	void method(int n)
	{
		done[0] = done[1] = false;
		for (int i = 2; i <= floor(sqrt(n)+0.5); i++) {
			if (done[i]) {
				for (int j = i * i; j <= n; j+=i) {
					done[j] = false;
				}
			}
		}
	}
    int countPrimes(int n) {
		if (n <= 2) return 0;
		method(n);
		int solve = 0;
		for (int i = 2; i < n; i++) {
			if (done[i]) solve++;
		}
		return solve;
    }
};
