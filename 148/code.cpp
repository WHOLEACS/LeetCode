/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	   int val;
 *	   ListNode *next;
 *	   ListNode() : val(0), next(nullptr) {}
 *	   ListNode(int x) : val(x), next(nullptr) {}
 *	   ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	//时间复杂度：O(nlogn) 空间复杂度：O(1)
	//归并排序-链表
	//快慢指针寻找中间节点
	ListNode* mid_node(ListNode* head, ListNode* tail)
	{
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != nullptr)
		{
			fast = fast->next;
			if (fast == nullptr) break;
			fast = fast->next;
			if (fast == nullptr) break;
			slow = slow->next;
		}
		return slow;
	}
	//链表合并	递归：返回值 调用单元 终止条件
	ListNode* merge_node(ListNode* List_1, ListNode* List_2)
	{
		if (List_1 == nullptr) return List_2;
		if (List_2 == nullptr) return List_1;
		ListNode* pNode = nullptr;
		if (List_1->val < List_2->val) {
			pNode = List_1;
			pNode->next = merge_node(List_1->next, List_2);
			
		} else {
			pNode = List_2;
			pNode->next = merge_node(List_1, List_2->next);
		}
		return pNode;
	}
	//递归：返回值 调用单元 终止条件
	ListNode* merge_sort(ListNode* head, ListNode* tail)
	{
		//寻找中间节点
		if (head == tail) return head;
		//快慢指针寻找中间节点
		ListNode* mid = mid_node(head, tail);
		ListNode* Next = mid->next;
		mid->next = nullptr;
		ListNode* left = merge_sort(head, mid);
		ListNode* right = merge_sort(Next, tail);
		//有序链表合并
		return merge_node(left, right);
	}
	ListNode* sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode* pNode = head;
		while (pNode->next != nullptr) {
			pNode = pNode->next;
		}
		return merge_sort(head, pNode);
	}
};
