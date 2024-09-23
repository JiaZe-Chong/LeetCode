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
        if (!head || !head->next)
            return head;
        
        ListNode* tail = nullptr;
        ListNode* ptr = head->next;
        
        while(ptr) {
            head->next = tail;
            tail = head;
            head = ptr;
            ptr = ptr->next;       
        }
        head->next = tail;
           
        return head;   
    }
};