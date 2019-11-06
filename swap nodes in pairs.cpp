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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* next = head->next;
        ListNode* tail = swapPairs(next-> next);
        next->next =head;
        head ->next = tail;
        head = next;
        return head;
    }
};
