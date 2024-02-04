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
        if (!head || !head->next) return nullptr;
        
        ListNode* behindSlow = head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next) {
            if (slow != head) behindSlow = behindSlow->next;
            slow = slow->next;
            fast = fast->next;
            
            if (fast->next) fast = fast->next;
        }
        
        behindSlow->next = behindSlow->next->next;
        
        return head;
    }
};