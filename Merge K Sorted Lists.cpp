/*
Use divide-and-conquer method to solve this problem,every time we just merge two
lists, all difficulties lie in merging. First get a new node, we see it as the virtual
root, get a copy of it to loop, everytime we put a new next into this list and when we
get the result, we delete the virtual root and return.

Time: O(nlogm) ,m = len of lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int listSize = lists.size();
        if(listSize == 0)
            return NULL;
        return divideAndConquer(lists,0,listSize-1);
    }
private:
    ListNode* divideAndConquer(vector<ListNode*>& lists, int start, int end)
    {
        if(start<end)
        {

            int mid = (start + end ) / 2 ;
            auto left = divideAndConquer(lists,start,mid);
            auto right = divideAndConquer(lists,mid+1,end);

            ListNode* result = new ListNode(-1);
            ListNode* temp = result;

            while(left && right)
            {
                if(left->val<right->val)
                {
                    temp->next = left;
                    left = left->next;
                }
                else
                {
                    temp->next = right;
                    right = right->next;
                }
                temp = temp->next;
            }

            if(left)
                temp->next = left;
            else if(right)
                temp->next = right;

            auto res = result->next;
            delete result;
            return res;
        }
        else
            return lists[start];

    }
};
