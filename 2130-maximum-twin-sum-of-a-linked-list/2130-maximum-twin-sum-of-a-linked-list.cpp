class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;

        // Find middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode *prev = nullptr, *curr = slow;
        while (curr) {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Calculate maximum twin sum
        int ans = 0;
        ListNode *first = head, *second = prev;

        while (second) {
            ans = max(ans, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return ans;
    }
};