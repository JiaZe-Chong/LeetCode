class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector< vector<int> > vvi;
        
        for (auto a : points) vvi.push_back( { a[0] * a[0] + a[1] * a[1], a[0], a[1] } );
        
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > pq( vvi.begin(), vvi.end() );
        
        vector<vector<int>> ret;
        
        while (k--) {
            ret.push_back( {pq.top()[1], pq.top()[2]} );
            pq.pop();
        }
        
        return ret;
    }
};