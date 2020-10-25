class Solution {
public:
    //双指针 + 贪心 时间复杂度：O(n) 空间复杂度：O(1)
    int longestMountain(vector<int>& A) {
        int len = A.size();
        if(len <= 2) return 0;
        int solve = 0;
        int l = 0 , r = 1;
        bool up = false , down = false;
        while(r < len && l < r)
        {
            if(A[r] > A[l]) {
                up = true;
                while(r+1 < len && A[r+1] > A[r]) {
                    r++;
                }
                if(r+1 < len && A[r+1] < A[r]) {
                    down = true;
                    while(r+1 < len && A[r+1] < A[r]) {
                        r++;
                    }
                }
            }
            if(up && down) {
                solve = max(solve,r-l+1);
            }
            l = r;
            r++;
            up = down = false;
        }
        return solve;
    }
};
