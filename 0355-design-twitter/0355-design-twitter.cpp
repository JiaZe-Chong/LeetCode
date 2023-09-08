class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        vp.push_back( {userId, tweetId} );
    }
    
    vector<int> getNewsFeed(int userId) {
        
        vector<int> ret;
        
        unordered_set<int> follows = um[userId];
        
        for (int i = vp.size() - 1; i >= 0; i--) {
            if ( ret.size() == 10 ) break;
            
            if ( follows.find( vp[i].first ) != follows.end() || vp[i].first == userId )
                ret.push_back( vp[i].second );
        }
        
        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        um[followerId].insert( followeeId );
    }
    
    void unfollow(int followerId, int followeeId) {
        um[followerId].erase( followeeId );
    }
    
    //user, tweet
    vector< pair< int, int > > vp;
    //user, following
    unordered_map< int, unordered_set<int> > um;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */