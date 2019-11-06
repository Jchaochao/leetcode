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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast,*slow;
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        fast = head;
        slow = head;
        for(int i = 0;i<n;++i)
        {
            fast = fast->next;
        }
        int count = 0;
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
            prev = prev->next;
            count ++;
        }
        if(count == 0 )
            return head->next;
        prev->next = slow->next;
        return head;
    }
};
