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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) {
            return NULL;
        }
        if(head->next == NULL) {
            return head;
        }
        ListNode* p1 = head;
        int n;
        for(n = 1; p1->next != NULL; n++) {
            p1 = p1->next;
        }
        p1->next = head;//making the ring circular

        ListNode* p2 = head;
        for(int i = 1; i < n-(k%n); i++) {
            p2 = p2->next;
        }
        head = p2->next;
        p2->next = NULL;
        return head;
    }
};