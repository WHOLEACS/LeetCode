class Solution {
public:
	static int judge(int temp)
	{
		int num = 0;
		while(temp)
		{
			temp = temp&(temp-1);
			num++;
		}
		return num;
	}
	static bool cmp(const int& ind_1 , const int& ind_2)
	{
		int num_1 = judge(ind_1) , num_2 = judge(ind_2);
		return num_1 != num_2 ? num_1 < num_2 : ind_1 < ind_2;
	}
	//重排数组，按照二进制表示中1的个数进行从小到大的排序，如果数目相同，就按照元素大小升序排列
    vector<int> sortByBits(vector<int>& arr) {
		if (arr.size() <=1 ) return arr;
		sort(arr.begin() , arr.end() , cmp);
		return arr;
    }
};
