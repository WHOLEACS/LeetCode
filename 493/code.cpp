typedef long long LL;
class Solution {
private:
    int solve = 0;
public:
    //递归：返回值 调用单元 终止条件
    void merge_sort(vector<int>& nums, int l, int r)
    {
        if (l >= r) return;
        int mid = l + ((r - l) >> 1);
        merge_sort(nums, l, mid);
        merge_sort(nums, mid + 1, r);
        vector<int> temp;
        temp.clear();
        int l1 = l, l2 = mid + 1;
        int index = l2;
        while (l1 <= mid && l2 <= r) {
            if (nums[l1] <= nums[l2]) {
                //此时需要计算逆序对
                while (index <= r && 1l * nums[index] * 2 < nums[l1]) {
                    index++;
                }
                solve += index - mid - 1;
                temp.emplace_back(nums[l1]);
                l1++;
            } else {
                temp.emplace_back(nums[l2]);
                l2++;
            }
        }
        while (l1 <= mid) {
            while (index <= r && 1l * nums[index] * 2 < nums[l1]) {
                index++;
            }
            solve += index - mid - 1;
            temp.emplace_back(nums[l1]);
            l1++;
        }
        while (l2 <= r) {
            temp.emplace_back(nums[l2]);
            l2++;
        }
        for (int i = 0; i < temp.size(); i++)
        {
            nums[i+l] = temp[i];
        }
        return;
    }
    //分治法，归并排序
    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return 0;
        merge_sort(nums, 0, len-1);
        return solve;
    }
}; 
