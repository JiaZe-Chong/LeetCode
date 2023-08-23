class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        deque<int> dq;
        int left = 0, right = 0;
        
        while ( right < nums.size() ) {
                
            bool hit = false;
            while ( !dq.empty() && nums[right] > nums[dq.back()] ){
                hit = true;
                dq.pop_back();
            }
            if ( hit || dq.empty() ) dq.push_back( right );
            else{
                while ( !dq.empty() && (nums[right] > nums[dq.front()] || dq.front() < left) ){
                    dq.pop_front();
                }
                dq.push_front( right );
            } 
                
            if ( right - left + 1 == k ){
                ans.push_back( nums[dq.back()] );
                left++;
                if ( dq.back() < left ) dq.pop_back();
            }

            right++;

            
        }
        
        return ans;
    }
};