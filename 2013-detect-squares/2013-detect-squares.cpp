class DetectSquares {
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        m[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        
        int ret = 0;
        
        for (auto it : m) {
            for ( auto it2 : it.second ) {
                
                if ( it.first == x || it2.first == y || abs( it.first - x ) != abs( it2.first - y ) )
                    continue;
                
                ret += m[it.first][it2.first] * m[x][it2.first] * m[it.first][y];
            }
        }
        
        return ret;
    }
    
    //m[x][y] = n
    unordered_map< int, unordered_map< int, int > > m;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */