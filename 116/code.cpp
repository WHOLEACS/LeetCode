/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
	//消耗常量的空间  完美二叉树  利用了上层已经构建完成的节点，它们会构成一个链表的形式，遍历这个链表，把下一层的节点链接起来即可。
	//空间复杂度：O(1)
    Node* connect(Node* root) {
        if(root==nullptr || (root->left == nullptr && root->right == nullptr)) return root;
		Node* last = root;
		Node* now_floor = root->left;
		Node* first = now_floor;
		while(now_floor != nullptr)
		{
			Node* pNode = last;
			while(pNode!=nullptr)
			{
				Node* next = nullptr;
				if(now_floor == pNode->left) next = pNode->right;
				else {
					pNode = pNode->next;
					if(pNode!=nullptr) next = pNode->left;
				}
				now_floor->next = next;
				now_floor = next;
			}
			last = first;
			now_floor = last->left;
			first = now_floor;
		}
		return root;
    }
};
