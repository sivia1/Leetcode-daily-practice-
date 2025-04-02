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
//Find the mid of ll using slow and fast pointer
//Reverse the rest of sub list
//Then re order list

    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }

    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return;
        }
        ListNode* mid = middle(head);
        ListNode* reverse = reverseList(mid->next);
        mid->next = NULL;

        ListNode* c1 = head;
        ListNode* c2 = reverse;
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