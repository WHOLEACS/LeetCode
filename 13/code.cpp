class Solution {
private:
    unordered_map<string, int> mp;
public:
    void init() {
        mp["I"] = 1;
        mp["V"] = 5;
        mp["X"] = 10;
        mp["L"] = 50;
        mp["C"] = 100;
        mp["D"] = 500;
        mp["M"] = 1000;
        mp["IV"] = 4;
        mp["IX"] = 9;
        mp["XL"] = 40;
        mp["XC"] = 90;
        mp["CD"] = 400;
        mp["CM"] = 900;
    }

    int romanToInt(string s) {
        int solve = 0, len = s.size();
        init();
        for (int i = 0; i < len; i++) {
            string temp = s.substr(i, 2);
            if (mp.find(temp) != mp.end()) {
                solve += mp[temp];
                i++;
            } else {
			    // 注意char转string的方法，char存放的是内容，string存放的是地址，不可以直接赋值	
                solve += mp[string(1, s[i])];
            }
        }
        return solve;
    }
};
