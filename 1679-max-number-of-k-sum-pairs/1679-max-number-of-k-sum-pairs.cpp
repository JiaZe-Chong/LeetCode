class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int ret = 0;
        
        for (int i : nums) {
            
            int dif = k - i;
            if (m[dif] == 0)
                m[i]++;
            else {
                m[dif]--;
                ret++;
            }
                
        }
        
        return ret;
    }
};