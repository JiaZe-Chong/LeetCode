class Node {
public:
    Node( int k, int v ) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
    
    int key;
    int val;
    Node* next;
    Node* prev;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        
        cap = capacity;
        
        left = new Node( -1, -1 );
        right = new Node( -1, -1 );
        
        left->next = right;
        right->prev = left;
        
    }
    
    int get(int key) {
        
        if ( m.find( key ) != m.end() ) {
            
            remove(m[key]);
            insert(m[key]);
            return m[key]->val;
            
        }
        
        return -1;
        
    }
    
    void put(int key, int value) {

        if ( m.find(key) != m.end() ) {
            
            remove( m[key] );
            delete m[key];
            
        }
        
        m[key] = new Node( key, value );
        insert( m[key] );
        
        if ( m.size() > cap ) {
            
            Node* lru = left->next;
            remove( lru );
            m.erase( lru->key );
            delete lru;
            
        }
        
    }
    
private:
    
    void remove( Node* n ) {
        
        Node* prev = n->prev;
        Node* next = n->next;
        
        prev->next = next;
        next->prev = prev;
        
    }
    
    void insert( Node* n ) {
        
        Node* prev = right -> prev;
        Node* next = right;
        
        prev->next = n;
        next->prev = n;
        
        n->next = next;
        n->prev = prev;
        
    }
    
    int cap;
    unordered_map<int, Node*> m;
    Node* left;
    Node* right;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */