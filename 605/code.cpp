class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		if (n == 0) return true;
		int solve = 0, len = flowerbed.size();
		if (len == 1) {
			if (n > 1 || flowerbed[0] == 1) {
			  return false;  
			} 
			return true;
		}
		for (int i = 0; i < len; i++) {
			if (flowerbed[i] == 0) {
				if (i == 0) {
					if (flowerbed[1] == 0) {
						flowerbed[0] = 1;
						solve++;
					}
				} else if (i == len - 1) {
					if (flowerbed[i - 1] == 0) {
						flowerbed[i] = 1;
						solve++;
					}
				} else {
					if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
						flowerbed[i] = 1;
						solve++;
					}
				}
			}
		}
		return solve >= n;
	}
};
