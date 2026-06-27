/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || left==right)
        {
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        for(int i=1;i<left;i++)
        {
            prev=prev->next;
        }
        ListNode* curr = prev->next;
//1->  2->3->4  ->5  p->curr->n
//p    p2 c n p2
        ListNode* prev2 = NULL;
        for(int i=left;i<=right;i++)
        {
            ListNode* next = curr->next;
            curr->next = prev2;
            prev2 = curr;
            curr = next;
        }
        prev->next->next = curr;
        prev->next = prev2;
        return dummy->next;
    }
};