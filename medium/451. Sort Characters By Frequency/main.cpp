class Solution {
public:
    
    void repeat(char c, int freq, string&s){
        while (freq-->0)
            s+= c;
    }
    string frequencySort(string s) {
        map<char, int> freq;
        for (char c: s)
            freq[c]++;
        priority_queue<pair<int,char>> pq;
        for (auto item: freq)
            pq.push(pair<int,char>(item.second, item.first));
        
        string ret = "";
        while (!pq.empty()){
            repeat(pq.top().second, pq.top().first, ret);
            pq.pop();
        }

        
        return ret;
        
    }
};
