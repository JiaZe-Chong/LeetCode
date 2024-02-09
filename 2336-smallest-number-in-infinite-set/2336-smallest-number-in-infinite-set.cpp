class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int i = 1;
        while (removed.contains(i)) i++;
        removed.insert(i);
        return i;
    }
    
    void addBack(int num) {
        if (removed.contains(num))
            removed.erase(num);
    }
    
    set<int> removed;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */