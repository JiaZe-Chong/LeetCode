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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* dummy = new ListNode( -1, head );
        
        ListNode* prev = dummy;
        ListNode* curr = prev->next;
        ListNode* temp = nullptr;
        
        int count = k;
        
        while ( curr ) {
            
            if ( count > 1 ) {
                
                temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;
                
                count--;
                
            }
            else {
                
                prev = curr;
                curr = curr->next;
                count = k;
                
                ListNode* check = curr;
                for (int i = 0; i < k; i++) {
                    
                    if ( !check ) return dummy->next;
                    check = check->next;
                    
                }
                
            }
            
            
            
        }
        
        
        return dummy->next;
        
    }
};