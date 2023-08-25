/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if ( !head ) return nullptr; 
        
        Node* ans = new Node( -1 );
        Node* cur = ans;
        unordered_map< Node*, Node* > m;
        
        while ( head ){
            
            m[head] = cur;
            cur->val = head->val;
            if ( head->next && !m[head->next] ) {
                m[head->next] = new Node( head->next->val );
            }
            cur->next = m[head->next];
            
            if ( head->random && !m[head->random] ) {
                m[head->random] = new Node( head->random->val );
            }
            cur->random = m[head->random];
            
            head = head -> next;
            cur = cur->next;
        }
        
        return ans;
        
        
    }
};