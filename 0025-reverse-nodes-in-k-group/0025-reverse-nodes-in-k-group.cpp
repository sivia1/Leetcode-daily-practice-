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
//idea : reverse the first k nodes in the list then reverse the next k nodes and so on. If there are fewer than k nodes left, leave the nodes as they are
//return the modified list after reversing the nodes in each group of k
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;
        while(true) {
            ListNode* kth = getKth(groupPrev, k);
            if(!kth) {
                break;
            }
            ListNode* groupNext = kth->next;
            ListNode* prev = kth->next;
            ListNode* curr = groupPrev->next;
            while(curr != groupNext) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            ListNode* tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp;
        }
        return dummy->next;
    }

private:
    ListNode* getKth(ListNode* curr, int k) {
        while(curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};