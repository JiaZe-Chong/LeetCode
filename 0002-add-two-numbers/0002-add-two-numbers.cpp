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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        bool carry = false;
        ListNode* ans = new ListNode( -1, nullptr );
        ListNode* cur = ans;
        
        while ( carry || l1 || l2 ) {
            int curr = 0;
            
            if ( l1 ) {
                curr += l1-> val;
                l1 = l1->next;
            }
            if ( l2 ) {
                curr += l2->val;
                l2 = l2->next;
                
            }
            if ( carry ) curr++;
            
            cur -> next = new ListNode( curr % 10 );
            carry = curr / 10;
            cur = cur -> next;
            
            
        }
        
        return ans -> next;
    }
};