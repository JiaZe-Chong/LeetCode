/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if ( !node ) return nullptr;
        
        unordered_map<Node*, Node*> um;
        queue<Node*> qn;
        
        um[ node ] = new Node( node->val );
        qn.push( node );
        
        while ( !qn.empty() ) {
            
            Node* cur = qn.front();
            qn.pop();
            
            for (auto a : cur->neighbors) {
                
                if ( !um[a] ) {
                    
                    um[a] = new Node( a->val );
                    qn.push( a );
                    
                }
                
                um[ cur ]->neighbors.push_back( um[a] );
                
            }
         
        }
        
        return um[ node ];
    }
};