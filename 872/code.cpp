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
    void ergodic(TreeNode* root, vector<int>& vec) {
        stack<TreeNode*> st;
        while (!st.empty()) {
            st.pop();
        }
        // 中序遍历 左根右
        TreeNode* pNode = root;
        while (pNode != nullptr) {
            st.push(pNode);
            pNode = pNode->left;
        }
        while (!st.empty()) {
            TreeNode* now_root = st.top();
            st.pop();
            if (now_root->left == nullptr && now_root->right == nullptr) {
                vec.emplace_back(now_root->val);
            }
            // 把当前节点作为根节点，尝试寻找右子节点
            if (now_root->right != nullptr) {
                pNode = now_root->right;
                while (pNode != nullptr) {
                    st.push(pNode);
                    pNode = pNode->left;
                }
            }
        }
        return;
    }

    // 迭代方法
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        vector<int> vec1;
        vec1.clear();
        vector<int> vec2;
        vec2.clear();
        ergodic(root1, vec1);
        ergodic(root2, vec2);
        if (vec1.size() != vec2.size()) {
            return false;
        }
        for (int i = 0; i < vec1.size(); i++) {
            if (vec1[i] != vec2[i]) {
                return false;
            }
        }
        return true;
    }
};
