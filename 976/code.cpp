class Solution {
public:
    //三角形：两边之和大于第三边
    int largestPerimeter(vector<int>& A) {
        int len = A.size();
        if (len < 3) return 0;
        sort(A.begin(), A.end());
        for (int i = len - 1; i >= 2; i--) {
            if (A[i - 1] + A[i - 2] > A[i]) return A[i - 1] + A[i - 2] + A[i];
        }
        return 0;
    }
};
