struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* head = result; // Keep a reference to the head of the result list
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int l1_val = (l1 == nullptr) ? 0 : l1->val;
            int l2_val = (l2 == nullptr) ? 0 : l2->val;
            
            int sum = l1_val + l2_val + carry;
            carry = sum / 10;

            result->next = new ListNode(sum % 10); // Create a new node with the digit
            result = result->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return head->next; // Return the actual result list (skip the dummy node)
    }
};
