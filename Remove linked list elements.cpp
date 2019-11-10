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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre,*cur,*next;
        ListNode* vhead = new ListNode(-1);
        vhead->next = head;
        cur = head;
        pre = vhead;
        while(cur)
        {
            if(cur->val==val)
            {
                pre->next = cur->next;
            }
            else
            {
                pre = pre->next;
            }
            cur = cur->next;
        }
        return vhead->next;
    }
};
