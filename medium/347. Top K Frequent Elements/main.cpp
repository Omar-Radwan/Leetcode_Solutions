class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int i: nums) freq[i]++;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (auto it: freq){
            auto [v,f] = it;
            pq.push(pair<int,int>(f,v));
            if (pq.size() > k) pq.pop();
        }
        vector<int> ret;
        while (!pq.empty()){
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};
