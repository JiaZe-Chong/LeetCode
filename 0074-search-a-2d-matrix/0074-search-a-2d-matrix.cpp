class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1;
        
        while ( top <= bottom ){
            
            int middle = (top + bottom) / 2;
            
            if ( matrix[middle][0] <= target && matrix[middle][n - 1] >= target ){
                
                int left = 0, right = n - 1;
                
                while ( left <= right){
                    
                    int mid = ( left + right ) / 2;
                    
                    if ( matrix[middle][mid] == target ) return true;
                    else if ( matrix[middle][mid] > target ) right = mid - 1;
                    else left = mid + 1;
                    
                }
                
                return false;
            }
            else if ( matrix[middle][0] > target ) bottom = middle - 1;
            else top = middle + 1;
            
            
        }
        
        return false;
    }
};