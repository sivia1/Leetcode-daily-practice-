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
    ListNode* reverseList(ListNode* head) {
        if(!head) {
            return head;
        }
        ListNode* prev = NULL;
        while(head) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* prev = dummy;
        
        // Loop to determine the lengths of groups
        for(int len = 1; len < 1e5 && head; len++) {
            ListNode* tail = head;
            ListNode* nextHead;
            
            // Determining the length of the current group
            // Its maximum length can be equal to len
            int j = 1;
            while(j < len && tail && tail -> next) {
                tail = tail -> next;
                j++;
            }
            
            // Head of the next group
            nextHead = tail -> next;
            
            if((j % 2) == 0) {
                // If even sized group is found
                // Reversing the group and setting prev and head appropriately
                tail -> next = NULL;
                prev -> next = reverseList(head);
                prev = head;
                head -> next = nextHead;
                head = nextHead;
            } else {
                // If group is odd sized, then simply going towards the next group
                prev = tail;
                head = nextHead;
            }
        }
        
        // Returning the head
        return dummy -> next;

    }
};