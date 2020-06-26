class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int> v;
    MyHashSet() {
    }
    
    void add(int key) {
        if(v.empty())
            v.push_back(key);
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == key) {
                v[i] = key;
                return;
            }
        }
        v.push_back(key);
    }
    
    void remove(int key) {
        if(v.empty())
            return;
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == key) {
                v.erase(v.begin() + i);
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(v.empty())
            return false;
        for(int i = 0; i < v.size(); i++)
            if(v[i] == key)
                return true;
        return false;
    }
};

