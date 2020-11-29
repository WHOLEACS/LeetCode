typedef long long LL;
class Solution {
public:
    LL quick_add(LL a, LL b) {
        LL ans = 0;
        while (b) {
            if (b&1) ans += a;
            b >>= 1;
            a = a*2;
        }
        return ans;
    }
	LL my_pow(LL a, LL b) {
		LL ans = 1;
		while (b) {
			if (b&1) ans *= a;
			b >>= 1;
			a = quick_add(a, a);
		}
		return ans;
	}
	//寻找字符串的下一个排列
    int nextGreaterElement(int n) {
		string s = "";
		while (n) {
			s += (n%10) + '0';
			n /= 10;
		}
		reverse(s.begin(), s.end());
		//找到最后一个高点
		int len = s.size();
		int last_high = -1;
		for (int i = 0; i < len - 1; i++) {
			if (s[i] < s[i+1]) last_high = i + 1;
		}
		if (last_high == -1) return -1;
		//寻找高点后面正好大于前面元素的位置
		int index = last_high;
		while (index < len && s[index] > s[last_high - 1]) {
			index++;
		}
		index--;
		swap(s[last_high - 1], s[index]);
		//把last_high 到 最后的元素按照升序排列
		for (int i = 0; i < (len - last_high) / 2; i++) {
			swap(s[i + last_high], s[len - 1 - i]);
		}
		LL solve = 0;
		for (int i = 0; i < len; i++) {
			solve = 1l*solve * 10 + (s[i] - '0');
		}
        LL max_int = my_pow(2, 31) - 1;
		return solve > max_int ? -1 : solve;
    }
};
