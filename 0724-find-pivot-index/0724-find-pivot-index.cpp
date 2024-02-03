class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 0;
        right[0] = 0;
        
        for (int i = 1; i < n; i++) left[i] = left[i - 1] + nums[i - 1];
        for (int i = 1; i < n; i++) right[i] = right[i - 1] + nums[n - i];
        
        
        for (int i = 0; i < n; i++)
            if (left[i] == right[n - i - 1]) return i;
        
        // for (int i = 0; i < n; i++) cout << left[i] << " ";
        // cout << endl;
        // for (int i = 0; i < n; i++) cout << right[i] << " ";
        
        return -1;
    }
};