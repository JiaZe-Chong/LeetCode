/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        if (grid.size() == 1) {
            Node* node = new Node(grid[0][0], true);
            return node;
        }
        
        bool diff = false;
        int comp = grid[0][0];
        for (const auto& arr : grid) {
            for (const auto& ele : arr) {
                if (comp != ele) {
                    diff = true;
                    break;
                }
            }
        }
        
        if (!diff) {
            Node* node = new Node(grid[0][0], true);
            return node;
        }
        
        int n = grid.size();
        int size = n / 2;
        
        vector<vector<int>> upperLeft(size, vector<int>(size));
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                upperLeft[i][j] = grid[i][j];
        
        vector<vector<int>> upperRight(size, vector<int>(size));
        for (int i = 0; i < size; i++)
            for (int j = size; j < n; j++)
                upperRight[i][j - size] = grid[i][j];
        
        vector<vector<int>> lowerLeft(size, vector<int>(size));
        for (int i = size; i < n; i++)
            for (int j = 0; j < size; j++)
                lowerLeft[i - size][j] = grid[i][j];
        
        vector<vector<int>> lowerRight(size, vector<int>(size));
        for (int i = size; i < n; i++)
            for (int j = size; j < n; j++)
                lowerRight[i - size][j - size] = grid[i][j];
        
        Node* node = new Node(grid[0][0], false, construct(upperLeft), construct(upperRight), construct(lowerLeft), construct(lowerRight));
        return node;
    }
};