class Solution {
public:
    struct entry{
      string name, city;
      int time, value, indx;
      vector<string> split(string &s){
            stringstream ss(s);
            string intermediate;
            vector<string> ret;
            while  (getline(ss, intermediate, ','))
                ret.push_back(intermediate);
            return ret;
        }
        entry(string s, int i){
          vector<string> tmp = split(s);
          name = tmp[0];
          time = stoi(tmp[1]);
          value = stoi(tmp[2]);
          city = tmp[3];
          indx = i;
      }
        entry(const entry& x){
            name = x.name, city = x.city, time = x.time, value = x.value, indx = x.indx;
        }
      bool operator < (const entry& x) const{
            return time < x.time;
        }
        
    };
    vector<string> invalidTransactions(vector<string>& transactions) {
        
        unordered_set<int> removed;
        vector<string> ret;
        vector<entry> entries;
        
        for (int i = 0 ; i < transactions.size(); i++)
            entries.push_back(entry(transactions[i],i));
        
        sort(entries.begin(), entries.end());
        
        for (int i = 0 ; i < entries.size() ; i++){
            bool bad = entries[i].value > 1000;
            for (int j = i+1 ; j < entries.size() && entries[j].time - entries[i].time <= 60; j++){
                if (entries[i].name == entries[j].name && entries[i].city != entries[j].city){
                    removed.insert(entries[j].indx);
                    bad = true;
                }
            }
            if (bad) removed.insert(entries[i].indx);
        }
        
        for (int i : removed)
            ret.push_back(transactions[i]);
        
        
        
        return ret;
    }
};
