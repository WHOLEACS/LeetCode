/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	//插入排序：逐渐扩大有序范围  时间复杂度：O(n^2)
    ListNode* insertionSortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode* pNode = head;
		ListNode* Next = nullptr;
		ListNode* order_head = head;
		//pNode指向当前元素，表示当前要执行插入的链表节点
		while (pNode != nullptr) {
			Next = pNode->next;
			pNode->next = nullptr;
			ListNode* order = order_head;
			ListNode* pre = nullptr;
			if (pNode != order) {
				while (order != nullptr && order->val < pNode->val) {
					pre = order;
					order = order->next;
				}
				if (pre == nullptr) {
					pNode->next = order_head;
					order_head = pNode;
				}
				else {
					pNode->next = pre->next;
					pre->next = pNode;
				}
			} 
			pNode = Next;
		}
		return order_head;
    }
};
