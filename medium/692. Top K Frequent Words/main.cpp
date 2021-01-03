class Solution {
public:
    
    struct entry{
        string word; int rep;
        entry(string w, int r){
            rep = r, word = w;
        }
        
        entry (const entry& e){
            rep = e.rep, word = e.word;
        }
        
        bool operator < (entry e) const{
            if (rep != e.rep) return rep > e.rep;
            return word < e.word;
        }
        
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (string s: words)
            freq[s]++;
        
        priority_queue<entry> pq;
        for (auto it: freq){
            pq.push(entry(it.first, it.second));
            if (pq.size()>k) pq.pop();
        }
        
        
        vector<string> ret;
        while (!pq.empty()){
            ret.push_back(pq.top().word);
            pq.pop();
        }
        
        reverse(ret.begin(),ret.end());
        return ret;
        
    }
};
