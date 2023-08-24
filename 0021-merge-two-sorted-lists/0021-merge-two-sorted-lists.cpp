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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* ans = new ListNode( 0, nullptr );
        ListNode* cur = ans;
        
        while ( list1 || list2 ) {
            
            if ( list1 && list2 && list1->val < list2->val ) {
                
                cur -> next = new ListNode( list1->val );
                list1 = list1->next;
                cur = cur -> next;
                
            }
            else if ( list1 && list2 && list1->val >= list2->val ) {
                
                cur -> next = new ListNode( list2->val );
                list2 = list2->next;
                cur = cur -> next;
                
            }
            else if ( list1 ) {
                cur -> next = list1;
                break;
            }
            else {
                cur -> next = list2;
                break;
            }            
            
            
            
        }
        
        return ans -> next;
    }
};