class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> sp;
        int ret = 0;

        for (int i = 0; i < heights.size(); i++) {

            int start = i;

            while ( !sp.empty() && sp.top().second > heights[i] ) {

                int ind = sp.top().first;
                int height = sp.top().second;
                sp.pop();

                int width = sp.empty() ? i : i - sp.top().first - 1;
                ret = max( ret, width * height );

            }

            sp.push( {start, heights[i]} );

        }

        while ( !sp.empty() ) {
            int height = sp.top().second;
            sp.pop();

            int width = sp.empty() ? heights.size() : heights.size() - sp.top().first - 1;
            ret = max( ret, width * height );
        }

        return ret;
    }
};