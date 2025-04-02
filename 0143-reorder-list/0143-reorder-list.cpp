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

ListNode* middle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode* reverse(ListNode* head) {
    ListNode* current = head;
    ListNode* prev = nullptr;
    ListNode* forw = nullptr;

    while(current) {
        forw = current->next;
        current->next = prev;
        prev = current;
        current = forw;
    }
    return prev;
}

    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return;
        }

        ListNode* mid = middle(head);
        ListNode* reversed = reverse(mid->next);
        mid->next = NULL;

        ListNode* c1 = head;
        ListNode* c2 = reversed;
        ListNode* f1 = NULL;
        ListNode* f2 = NULL;

        while(c1 != NULL && c2 != NULL) {
            f1 = c1->next;
            f2 = c2->next;

            c1->next = c2;
            c2->next = f1;

            c1 = f1;
            c2 = f2;
        }
    }
};