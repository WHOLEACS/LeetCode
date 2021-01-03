/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    struct Node{
        ListNode* pre;
        int ind;
        ListNode* var;
        Node(ListNode* pre, int ind, ListNode* var):pre(pre),ind(ind),var(var) {}
    };
public:
    // 时间复杂度：O(n) 空间复杂度：O(1)
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) return head;
        Node* big = new Node(nullptr, 0, head);
        while (big->var != nullptr && big->var->val < x) {
            big->pre = big->var;
            big->var = big->var->next;
            big->ind++;
        }
        if (big->var == nullptr) return head;
        Node* small = new Node(big->var, big->ind + 1, big->var->next);
        ListNode* new_head = head;
        while (small->var != nullptr) {
            ListNode* next_node = small->var->next;
            if (small->var->val < x && small->ind > big->ind) {
                // 此时需要进行交换
                if (small->pre != nullptr) {
                    small->pre->next = next_node;
                }
                small->var->next = big->var;
                if (big->pre != nullptr) {
                    big->pre->next = small->var;
                }
                big->pre = small->var;
                if (big->ind == 0) {
                    new_head = small->var;
                }
                big->ind++;
            }
            else {
                small->pre = small->var;
            }
            small->var = next_node;
            small->ind++;
        }
        small = nullptr, big = nullptr;
        delete small;
        delete big;
        return new_head;
    }
};
