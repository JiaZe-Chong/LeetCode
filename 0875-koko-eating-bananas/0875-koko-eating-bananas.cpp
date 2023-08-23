class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1, right = *max_element( piles.begin(), piles.end() );
        
        while ( left <= right) {
            
            int mid = ( left + right ) / 2;
            
            if ( calculateHours( piles, mid ) <= h ) right = mid - 1;
            else left = mid + 1;
        
        }
        
        return left;
        
    }
    
    long long calculateHours( const vector<int>& piles, int eatingSpeed ){
        long long ans = 0;
        for (int i : piles) ans += ceil( i / (double)eatingSpeed );
        return ans;
    }
};