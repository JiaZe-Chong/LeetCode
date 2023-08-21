class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int head = 0, tail = numbers.size() - 1;
        
        while ( head < tail ){
            int k = numbers[head] + numbers[tail];
            
            if ( k == target ) break;
            else if ( k > target ) tail--;
            else head++;
        }
            
        return { head + 1, tail + 1 };
        
    }
};