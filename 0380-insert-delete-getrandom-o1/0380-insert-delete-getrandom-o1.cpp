class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        if (m.contains(val))
            return false;
        
        m[val] = vec.size();
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!m.contains(val))
            return false;
        
        int temp = vec.back();
        m[temp] = m[val];
        vec[m[temp]] = temp;
        vec.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        int ind = rand() %vec.size();
        return vec[ind];
    }
    
    vector<int> vec;
    unordered_map<int, int> m;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */