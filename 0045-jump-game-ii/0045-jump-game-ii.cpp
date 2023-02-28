class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(); 

        int jumps[n];
        jumps[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--){
            int m = INT_MAX;
            for (int j = 1; j + i < n && j <= nums[i]; j++){
                if (jumps[i + j] == -1) continue;
                m = min(m, jumps[i + j]);
            }
            if (m == INT_MAX) m = -2;
            jumps[i] = m + 1;
            cout << jumps[i] << endl;
        }
        return jumps[0];
    }
};