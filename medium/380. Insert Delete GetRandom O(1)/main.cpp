class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    unordered_map<int,int> vi, iv;
    int size = 0;
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (vi.count(val))
            return false;
        vi[val]=size,iv[size] =val;
        size++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!vi.count(val))
            return false;
        size--;
        int oldindex = vi[val];
        vi.erase(val), iv.erase(oldindex);
        if (size!=0){
            int last = iv[size];
            iv.erase(size), vi.erase(last);
            iv[oldindex] = last, vi[last]=oldindex;    
        }
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int random = rand()%size;
        return iv[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
