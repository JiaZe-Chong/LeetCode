class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int mx = -1;
        
        int head = 0, tail = height.size() - 1;
        
        while ( head < tail ){
            
            int area = ( tail - head ) * min( height[head], height[tail] );
            
            mx = max(area, mx);
            
            if ( height[head] > height[tail] ) tail--;
            else if ( height[head] < height[tail] ) head++;
            else{
                head++;
                tail--;
            }
            
        }
        return mx;
    }
};