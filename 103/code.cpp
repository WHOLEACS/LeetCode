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
private:
	vector<vector<int>> solve;
public:
	Solution() {
		solve.clear();
	}
	// bfs stack queue
	void bfs(TreeNode* root) {
		stack<TreeNode*> st;
		while (!st.empty()) st.pop();
		queue<TreeNode*> pq;
		while (!pq.empty()) pq.pop();
		vector<int> temp;
		temp.clear();
		pq.push(root);
		bool flag = false;
		while (!pq.empty()) {
			TreeNode* node = pq.front();
			pq.pop();
			temp.emplace_back(node->val);
			if (!flag) {
				if (node->left != nullptr) {
					st.push(node->left);
				}
				if (node->right != nullptr) {
					st.push(node->right);
				}
			} else {
				if (node->right != nullptr) {
					st.push(node->right);
				}
				if (node->left != nullptr) {
					st.push(node->left);
				}
			}
			if (pq.empty()) {
				solve.emplace_back(temp);
				temp.clear();
				while (!st.empty()) {
					pq.push(st.top());
					st.pop();
				}
				flag = !flag;
			}
		}
	}
	
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (root == nullptr) return {};
		bfs(root);
		return solve;
    }
};
