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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;
        
        ListNode* second = new ListNode();
        ListNode* secondHead = second;
        ListNode* first = head;
        
        while (first->next) {
            second->next = first->next;
            second = second->next;
            if (!first->next->next) break;
            first->next = first->next->next;
            first = first->next;
        }
        second->next = nullptr;
        first->next = secondHead->next;
        
        return head;
    }
};