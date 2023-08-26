class Solution {
public:
    int climbStairs(int n) {     
        vector<int> vi( n + 1 );
        vi[0] = 1;
        vi[1] = 1;
        for (int i = 2; i <= n; i++) vi[i] = vi[i - 1] + vi[i - 2]; 
        return vi[n];
    }
};