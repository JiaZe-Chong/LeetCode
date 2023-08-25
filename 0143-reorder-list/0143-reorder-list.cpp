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
    void reorderList(ListNode* head) {
        
        vector<int> vi;
        ListNode* cur = head;
        
        while (cur) {
            
            vi.push_back( cur->val );
            cur = cur->next;
            
        }
        
        cur = head;
        int i = 0;
        
        while ( cur ){
            
            if (!( i % 2) ){
                cur -> val = vi[i / 2];          
            }
            else {  
                cur -> val = vi[ vi.size() - i/2 - 1 ];     
            }
            
            cur = cur -> next;
            i++;
        }
    
    }

};