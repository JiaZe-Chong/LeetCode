class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        req.push_back(t);
        
        while(req.front() < t - 3000) req.pop_front();
        
        return req.size();
    }
    
    deque<int> req;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */