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
    ListNode* deleteMiddle(ListNode* head) {
        if (!(head->next))
            return nullptr;
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* behind_slow = head;
        
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            behind_slow = slow;
            slow = slow->next;
        }
        
        if (fast->next) {
            behind_slow = slow;
            slow = slow->next;
        }
        
        behind_slow->next = slow->next;
        
        return head;
    }
};