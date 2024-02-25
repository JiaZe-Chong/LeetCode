class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size() - 1;
        int l = 0;
        int r = n;
        int middle;
        
        while (r >= l) {
            
            middle = l + (r - l) / 2;

            if ((middle == 0 || nums[middle] > nums[middle - 1]) &&
                (middle == n || nums[middle] > nums[middle + 1]))
                break;
            else if (middle != 0 && nums[middle] < nums[middle - 1])
                r = middle - 1;
            else
                l = middle + 1;

        }
        
        return middle;
    }
};