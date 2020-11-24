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
	//dfs
	void dfs(TreeNode* root, int& solve)
	{
		if (root == nullptr) return;
		solve++;
		dfs(root->left, solve);
		dfs(root->right, solve);
	}
    int countNodes(TreeNode* root) {
		if (root == nullptr) return 0;
		int solve = 0;
		dfs(root, solve);
		return solve;
    }
};
