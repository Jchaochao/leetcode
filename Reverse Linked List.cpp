/*
I use a complex way to solve this problem that I create a double direction to copy this
list and then I reverse it.

Time:O(n)
Space:O(n)
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
    struct DoubleNode{
        int val;
        DoubleNode *pre;
        DoubleNode *next;
        DoubleNode(int x):val(x),next(NULL),pre(NULL){}
    };

    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        DoubleNode* root = new DoubleNode(-1);
        DoubleNode* iter = root;
        DoubleNode* p = root;
        while(head)
        {
            p = iter;
            iter->next = new DoubleNode(head->val);
            head = head->next;
            iter = iter->next;
            iter->pre = p;
        }
        root->next->pre = NULL;
        delete root;

        ListNode* result = new ListNode(-1);
        ListNode* temp = result;
        while(iter)
        {
            temp->next = new ListNode(iter->val);
            iter = iter->pre;
            temp = temp->next;
        }
        auto res = result->next;
        delete result;
        return res;
    };
};


/*
This is the author's Solution
Credit to : mp137
This is much easier:
*/

struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL) return head;

    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* nxt = head;
    // Nxt --> allows access to the next node when current node is reversed
	// Prev --> helps to point current node to previous node
	// Cur --> current node that is being reversed
    while(cur){
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}
