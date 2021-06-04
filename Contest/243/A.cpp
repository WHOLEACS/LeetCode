class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        auto find = [&](string& temp) {
            long long ans = 0;
            for (int i = 0; i < temp.size(); i++) {
                ans = ans * 10 + 1l * (temp[i] - 'a'); 
            }  
            return ans;
        };
        long long a = find(firstWord);
        long long b = find(secondWord);
        long long c = find(targetWord);
        return a + b == c;
    }
};
