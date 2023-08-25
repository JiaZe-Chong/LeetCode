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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        vector<int> vi;
        
        while (head) {
            vi.push_back( head->val );
            head = head -> next;
        }
            
        ListNode* ans = new ListNode( 0, nullptr );
        head = ans;
        for (int i = 0; i < vi.size(); i++) {
            
            if ( i == vi.size() - n ) continue;
            
            head -> next = new ListNode( vi[i] );
            head=head->next;          
            
        }

        return ans->next;
    }
};