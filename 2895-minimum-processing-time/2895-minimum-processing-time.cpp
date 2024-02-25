class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.rbegin(), tasks.rend());
        sort(processorTime.begin(), processorTime.end());
        
        int mx = 0;
        
        for (int i = 0; i < processorTime.size(); i++) {
            mx = max(mx, processorTime[i] + tasks[i * 4]);        
        }
        
        return mx;
    }
};