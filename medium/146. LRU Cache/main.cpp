class LRUCache {
public:
    
    struct entry{
        int key, value, time;
        entry(){}
        entry(const entry& x){
            key = x.key, value = x.value, time = x.time;
        }
        entry(int a, int b, int c){
            key = a, value = b, time = c;
        }
        
         bool operator < (const entry& x) const {
            return time < x.time;
        }
    };
    
    
    
    int max_size, time ;
    map<int,entry> mp;set<entry> st;
    
    LRUCache(int capacity) {
        max_size = capacity;
        time = 0;
    }
    
    void add_new(int key, int value){
        entry new_entry(key, value, time++);
        mp[key] = new_entry;
        st.insert(new_entry);
    }
    
    void add_existing(int key, int value){
        entry old_entry = mp[key];
        mp.erase(key), st.erase(old_entry);
        add_new(key, value);
    }
    
    int get(int key) {
        if (mp.count(key)){
            int value = mp[key].value;
            add_existing(key, value);
            return value;
        }
        else return -1;
    }
    

    void put(int key, int value) {
        if (mp.count(key)){
            add_existing(key,value);
        }
        else if (mp.size()+1<=max_size){
            add_new(key,value);
        }
        else {
            mp.erase(st.begin()->key);
            st.erase(st.begin());
            add_new(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
