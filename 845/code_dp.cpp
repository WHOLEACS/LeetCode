class Solution {
public:
    //dp 时间复杂度：O(n) 空间复杂度：O(n)
    int longestMountain(vector<int>& A) {
        int len = A.size();
        if(len<=2) return 0;
        vector<int> left(len,0);
        vector<int> right(len,0);
        left[0] = 1;
        right[len-1] = 1;
        for(int i=1;i<len;i++)
        {
            left[i] = A[i] > A[i-1] ? left[i-1]+1:1;
        }
        for(int i=len-2;i>=0;i--)
        {
            right[i] = A[i] > A[i+1] ? right[i+1]+1:1;
        }
        int solve = 0;
        for(int i=1;i<len;i++)
        {
            if(left[i] > 1 && right[i] > 1) {
                solve = max(solve,left[i]+right[i]-1);
            }
        }
        return solve;
    }
};
