/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	//递归：返回值 调用单元 终止条件
	//判断当前路径是否可行
	bool search(TreeNode* root, stack<int>& st)
	{
		if (root == nullptr) return false;
		if (st.empty()) return true;
		int flag = st.top();
		st.pop();
		if (flag == 0) return search(root->left, st);
		else return search(root->right, st);
	}
	//递归：返回值 调用单元 终止条件
	void find_high(TreeNode* root, int& h)
	{
		if (root == nullptr) return;
		h++;
		find_high(root->left, h);
	}
    //二分查找 利用位运算，完全二叉树的性质，父亲节点走向左节点的时候左移一位，低位补0，走向右节点的时候左移一位且+1，低位补1
    //这样的话根据当前的mid值的二进制表示即可知道从根节点到当前节点的路径过程
    //判断这个路径过程是否存在，根据结果进行二分指针的移动即可
    int countNodes(TreeNode* root) {
		if (root == nullptr) return 0;
		int h = 0;
		find_high(root, h);
		int l = (1 << (h - 1)) , r = (1 << h);
		while (l < r)
		{
			int mid = l + ((r - l) >> 1);
			//根据当前mid的二进制结果判断遍历路径，递归判断当前路径是否可行
			stack<int> st;
			while(!st.empty()) st.pop();
            //注意下面直接对mid进行了修改，所以这里需要预先把原来的mid存储下来方便使用
			int temp = mid;
			while (mid) {
				st.push(mid & 1);
				mid >>= 1;
			}
			st.pop();
			bool exists = search(root, st);
			if (exists) {
				l = temp + 1;
			} else {
				r = temp;
			}
		}
		return l - 1;
    }
};
