class Solution {
public:
	// 1.循环 2.记忆化搜索
    int fib(int n) {
		if (n <= 1) return n;
		int a = 0, b = 1;
		int temp;
		n -= 1;
		while (n--) {
			temp = b;
			b = a + b;
			a = temp;
		}
		return b;
    }
};

