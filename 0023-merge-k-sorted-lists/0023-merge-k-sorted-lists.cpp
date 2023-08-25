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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* ans = new ListNode();
        ListNode* cur = ans;
        int n = lists.size();
        
        while (true){
            
            int cont = false;
            int ind = -1;
            int mn = INT_MAX;
            
            for (int i = 0; i < n; i++) {
                
                if ( lists[i] && lists[i]->val <= mn ) {
                    ind = i;
                    mn = lists[i]->val;
                    cont = true;
                }
                
            }
            
            if ( !cont ) break;
            
            cur->next = new ListNode( mn );
            lists[ind] = lists[ind] -> next;
            cur = cur->next;
        }
        
        return ans -> next;
    }
};