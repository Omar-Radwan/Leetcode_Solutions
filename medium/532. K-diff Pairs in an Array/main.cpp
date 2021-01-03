class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;
        for (int i: nums) freq[i]++;
        
        int ans = 0 ;
        for (auto [x,f]: freq){
            int y = x+k;
            if (y==x && f >= 2) ans++;
            if (y!=x && freq.count(y)) ans++;
        }
        return ans;
    }
};
