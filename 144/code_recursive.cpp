/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	//递归:返回值 调用单元 终止条件
	void pre_order(TreeNode* root,vector<int>& solve)
	{
		if(root == nullptr) return;
		solve.push_back(root->val);
		pre_order(root->left,solve);
		pre_order(root->right,solve);
	}
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
		vector<int> solve;
		solve.clear();
		pre_order(root,solve);
		return solve;
    }
};
