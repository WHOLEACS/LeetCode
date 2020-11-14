typedef long long LL;
class Operations {
private:
	LL mul_res;
public:
	Operations() {

	}
	
	int minus(int a, int b) {
		LL solve_a = a;
		LL solve_b = b;
		solve_b = -solve_b;
		return solve_a + solve_b;
	}
	//快速乘   利用二进制
	int multiply(LL a, LL b) {
		if (a == 0 || b == 0) return 0;
		int num = 0;
		LL mul_a = a;
		LL mul_b = b;
		if (mul_a < 0) {
			num++;
			mul_a = -mul_a;
		}
		if (mul_b < 0) {
			num++;
			mul_b = -mul_b;
		}
		LL solve = 0;
		while (mul_b > 0)
		{
			if (mul_b&1) {
				solve = solve + mul_a;
			}
			mul_b >>= 1;
			mul_a <<= 1;
		}
		mul_res = solve;
		return num == 1 ? -solve : solve;
	}
	//二分
	int divide(int a, int b) {
		if (a == 0) return 0;
		if (b == 0) return -1;
		int num = 0;
		LL solve_a = a;
		LL solve_b = b;
		if (solve_a < 0) {
			num++;
			solve_a = -solve_a;
		}
		if (solve_b < 0) {
			num++;
			solve_b = -solve_b;
		}
		LL l = 0, r = solve_a + 1;
		while (l < r - 1)
		{
			LL mid = (l+r)>>1;
			multiply(solve_b , mid);
			LL now_mul = mul_res;
			if (now_mul == solve_a) {
				l = mid;
				break;
			}
			else if (now_mul > solve_a) {
				r = mid;
			}
			else if (now_mul < solve_a) {
				l = mid;
			}
		}
		return num == 1 ? -l : l;
	}
};

/**
 * Your Operations object will be instantiated and called as such:
 * Operations* obj = new Operations();
 * int param_1 = obj->minus(a,b);
 * int param_2 = obj->multiply(a,b);
 * int param_3 = obj->divide(a,b);
 */
