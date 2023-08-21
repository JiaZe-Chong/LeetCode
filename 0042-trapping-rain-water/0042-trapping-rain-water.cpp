class Solution {
public:
    int trap(vector<int>& height) {

        int ans = 0;
        int left = 0, right = height.size() - 1;
        int lmax = INT_MIN, rmax = INT_MIN;
        
        while ( left <= right ) {
            
            if ( height[left] >= lmax ){
                lmax = height[left];
                left++;
            }
            else if ( height[right] >= rmax ){
                rmax = height[right];
                right--;
            }
            else if ( lmax < rmax ){
                ans += lmax - height[left];
                left++;
            }
            else{
                ans += rmax - height[right];
                right--;
            }
            
            
        }
        return ans;
    }
};