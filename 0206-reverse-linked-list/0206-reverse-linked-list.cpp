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
//recursive approach: if there is only one node or head is empty we retunr the head
//Recursive approach works by reversing the list starting from the back.
//Assuming a sublist has already been reversed, say 
//n1->....nk-1->nk->nk+1->.....nm->NULL, here the list from nk+1 to nm has been reversed and we are at node nk. What we want to do is point nk+1's next pointer to nk.
//We get that by nk->next->next = nk

//Here at n1's next must point to NULL other wise the linked list will have a cycle 
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};