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
private:
    TreeNode* parent_x = nullptr;
    TreeNode* parent_y = nullptr;
    int deep_x, deep_y;
public:
    // 深度相同且父亲不同为堂兄弟节点
    void dfs(TreeNode* root, const int& x, const int& y, TreeNode* parent, int deep) {
        if (root == nullptr) {
            return;
        }
        if (parent_x != nullptr && parent_y != nullptr) {
            return;
        }
        if (root->val == x) {
            parent_x = parent;
            deep_x = deep;
        }
        if (root->val == y) {
            parent_y = parent;
            deep_y = deep;
        }
        dfs(root->left, x, y, root, deep + 1);
        dfs(root->right, x, y, root, deep + 1);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return false;
        }
        dfs(root, x, y, nullptr, 0);
        if (parent_x != parent_y && deep_x == deep_y) {
            return true;
        } 
        return false;
    }
};
