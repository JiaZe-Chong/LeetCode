class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        map<int, pair<int, int>> mp;
        map<int, bool> check;
        int mx = 0;
        
        for (int i : nums){

            if (check[i]) continue;
            check[i] = true;
            
            int l = i, r = i;
            if (mp.find( i + 1 ) != mp.end()){
                r = mp[i + 1].second;
            }
                
            if (mp.find( i - 1 ) != mp.end()){
                l = mp[i - 1].first;
            }
                
            mp[r] = {l, r};
            mp[l] = {l, r};
            mx = max(mx, r - l + 1);
        }
        return mx;
    }
};