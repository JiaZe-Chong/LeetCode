class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> vi(n + 1);
        vi[0] = 0;
        for (int i = 1; i <= n; i++) {
            
            if ( !( i % 2 ) ) vi[i] = vi[ i / 2 ];
            else vi[i] = vi[i - 1] + 1;
            
        }
        
        return vi;
    }
};