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
        if (node == nullptr) return nullptr;
        if (node -> neighbors.size() == 0) return new Node(node -> val);
        
        queue<Node*> Q;
        map<int, Node*> M;
        Q.push(node);
        while(!Q.empty()){
            Node* temp = Q.front();
            Q.pop();
            if (M[temp -> val] == nullptr){
                M[temp -> val] = new Node(temp -> val);
            }
            for (auto a : temp -> neighbors){
                if (M[a -> val] == nullptr){
                    Q.push(a);
                    M[a -> val] = new Node(a -> val);
                }
                M[temp -> val] -> neighbors.push_back(M[a -> val]);
            }
        }
        return M[1];
    }
};