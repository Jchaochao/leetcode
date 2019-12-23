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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd_last = head;
        ListNode* even_last;
        if(head)
            even_last = head->next;
        else
            even_last = head;
        while (even_last != NULL && even_last->next != NULL) {
            ListNode* odd = even_last->next;
            ListNode* even = (odd == NULL ? odd : odd->next);
            even_last->next = odd->next;
            odd->next = odd_last->next;
            odd_last->next = odd;
            odd_last = odd_last->next;
            even_last = even_last->next;
        }
        return head;
    }
};
