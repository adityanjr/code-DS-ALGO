class MyHashSet {
    vector<bool> keyPresent;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        keyPresent.assign(1000001, false);
    }
    
    void add(int key) {
        keyPresent[key] = true;
    }
    
    void remove(int key) {
        keyPresent[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return keyPresent[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */