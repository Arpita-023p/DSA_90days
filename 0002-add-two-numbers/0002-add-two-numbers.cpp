class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); // Helps us start the list
        ListNode* curr = dummy;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry != 0) {
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;

            // Calculate Sum and Carry
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            
            // Create new node with the digit part of sum
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            // Move to next nodes if they exist
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }

        return dummy->next; // Return the head of the actual result
    }
};