class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ret;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        
        for (int i = 0; i < intervals.size(); i++) {
            
            if ( intervals[i][0] > newEnd ) {
                ret.push_back( newInterval );
                copy( intervals.begin() + i, intervals.end(), back_inserter( ret ) );
                return ret;
            }
            else if ( intervals[i][1] < newStart ) {
                ret.push_back( intervals[i] );
            }
            else {
                newInterval[0] = min( newInterval[0], intervals[i][0] );
                newInterval[1] = max( newInterval[1], intervals[i][1] );
            }
            
        }
        
        ret.push_back( newInterval );
        
        return ret;
        
    }
};