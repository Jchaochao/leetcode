/*
This is easy, when you get a list, you just need to make it a circle, it means
end->next = head, then you need to re-calculate where it ends. For this part , we
know it loops k times, in fact ,it just need to loop k%count times, count is the number of
elements in this list. And finally, we got the end position is move end (count-k) times.

Time: O(n)
Space: O(1);
*/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;

        auto end = head;
        int count = 1;
        while(end->next)
        {
            end = end->next;
            count = count+1;
        }
        k = k % count;
        if(k==0)
            return head;
        else
        {
            end->next = head;
            int loop = count - k ;
            while(loop--)
            {
                end = end->next;
            }
            head = end->next;
        }
        end->next = NULL;
        return head;
    }
};
