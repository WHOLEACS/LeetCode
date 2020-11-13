/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	//空间复杂度：O(1) 时间复杂度：O(n)
	//递归 返回值 调用单元 终止条件
	void dfs(int index, ListNode*& last_odd, ListNode*& last_even, ListNode*& first_even, ListNode* pNode)
	{
		if(pNode == nullptr) return;
		ListNode* Next = pNode->next;
		if (index&1) {
			if(last_odd != nullptr) last_odd->next = pNode;
			last_odd = pNode;
			last_odd->next = nullptr;
		}
		else {
			if(last_even != nullptr) last_even->next = pNode;
			last_even = pNode;
			if(first_even == nullptr) first_even = pNode;
			last_even->next = nullptr;
		}
		dfs(index+1, last_odd, last_even, first_even, Next);
	}
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
		ListNode* last_odd = nullptr;
		ListNode* last_even = nullptr;
		int index = 1;
		ListNode* first_even = nullptr;
		dfs(index, last_odd, last_even, first_even, head);
		last_odd->next = first_even;
		return head;
    }
};
