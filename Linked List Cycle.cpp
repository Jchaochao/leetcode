/*
This is an easy problem, we have two pointer, head(which moves one step at one loop),
and twoStep(which moves two steps at one loop). If they meet, then there is a cycle, if
not then there is no cycle.
*/

/*
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
   bool hasCycle(ListNode *head) {
       ListNode* twoStep = head;
       while(twoStep)
       {
           if(twoStep->next && twoStep->next->next)
           {
               twoStep = twoStep->next->next;
               head = head->next;
           }
           else
           {
               return false;
           }
           if(head == twoStep)
               return true;
       }
       return false;

   }
};
