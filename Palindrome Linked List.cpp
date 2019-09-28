/*
This problem is to judge if a linked list is palindrome. And the follow-up is to use
O(N) time and O(1) space; This remind me of the reverse linked list, use O(1) space to
reverse a linked list in O(n) time. For this problem, we just need to reverse half of them
and then we get the pointer 'pre' pointing to the first half(which is reversed) and pointer'next'
point to the second half(which is not reversed), and compare it one by one. What's important
is how we deal with odd and even. If numbers of elements in list is odd, when we finish the reverse
part, we need to move 'next' to its next to skip the middle element(which is not needed to be compared).

Time: O(n)
Space: O(1)
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
    bool isPalindrome(ListNode* head) {
        if(!head)
            return true;

        int count = 0;
        int flag = 0;
        ListNode* temp = head;
        while(temp)
        {
            count+=1;
            temp = temp->next;
        }

        flag = count % 2;
        count/=2;

        delete temp;

        ListNode* next = head;
        ListNode* pre = NULL;
        ListNode* cur = head;
        for(int i = 0;i<count;++i)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        if(flag)
        {
            next = next->next;
        }
        for(int i = 0;i<count;++i)
        {
            if(pre->val != next->val)
                return false;
            pre = pre->next;
            next = next->next;
        }
        return true;
    }
};
