/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    /* Find the middle of the list. */
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *previous = NULL;
    struct ListNode *current = slow;

    while (current != NULL) {
        struct ListNode *next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    struct ListNode *left = head;
    struct ListNode *right = previous;

    while (right != NULL) {
        if (left->val != right->val) {
            return false;
        }
        left = left->next;
        right = right->next;
    }

    return true;
}
