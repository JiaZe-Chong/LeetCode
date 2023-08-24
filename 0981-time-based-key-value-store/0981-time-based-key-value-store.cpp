class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back( {timestamp, value} );
    }
    
    string get(string key, int timestamp) {
        
        const vector< pair <int, string> >& vp = m[key];
        
        int left = 0, right = vp.size() - 1;
        int mid = (left + right) / 2;
        
        string ret = "";
        
        while ( left <= right ) {
            
            mid = (left + right) / 2;
            
            if ( vp[mid].first > timestamp ) right = mid - 1;
            else{
                ret = vp[mid].second;
                left = mid + 1;
            } 
            
        }
        
        return ret;
        
    }
    
    unordered_map< string, vector< pair <int, string> > > m;
    
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */