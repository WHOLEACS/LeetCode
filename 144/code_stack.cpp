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
	//迭代 栈  前序遍历：根左右
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
		vector<int> solve;
		solve.clear();
		stack<TreeNode*> st;
		while(!st.empty()) st.pop();
		st.push(root);
		while(!st.empty())
		{
			TreeNode* now_root = st.top();
			st.pop();
			solve.push_back(now_root->val);
			if(now_root->right != nullptr) {
				st.push(now_root->right);
			}
			if(now_root->left != nullptr) {
				st.push(now_root->left);
			}
		}
		return solve;
    }
};
