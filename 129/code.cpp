/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *	   int val;
 *	   TreeNode *left;
 *	   TreeNode *right;
 *	   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef long long LL;
class Solution {
public:
	//从树的根节点到叶子节点只有一条路径
	//前序遍历：根左右
	//递归：返回值 调用单元 终止条件
	void dfs(TreeNode* root,LL& solve,int& now_sum)
	{
		if(root->left==nullptr && root->right==nullptr) {
			solve += now_sum;
			return;
		}
		if(root->left != nullptr) {
			now_sum = now_sum * 10 + root->left->val;
			dfs(root->left,solve,now_sum);
			now_sum -= root->left->val;
			now_sum /= 10;
		}
		if(root->right != nullptr) {
			now_sum = now_sum * 10 + root->right->val;
			dfs(root->right,solve,now_sum);
			now_sum -= root->right->val;
			now_sum /= 10;
		}
		return;
	}
	int sumNumbers(TreeNode* root) {
		if(root==nullptr) return 0;
		if(root->left==nullptr && root->right==nullptr) return root->val;
		LL solve = 0;
		int now = root->val;
		dfs(root,solve,now);
		return solve;
	}
};
