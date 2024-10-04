class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int lmax = INT_MIN, rmax = INT_MIN;
        int ans = 0;
        
        while (left <= right) {
            if (rmax < height[right]) 
                rmax = height[right--];
            else if (lmax < height[left]) 
                lmax = height[left++];
            else if (lmax < rmax) 
                ans += lmax - height[left++];
            else 
                ans += rmax - height[right--];
        }
        
        return ans;
    }
};