class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> nums_set, visited;
        
        for (auto&x: nums)
            nums_set.insert(x);
        
        int ans = 0;
        for (auto&x: nums_set){
            if (visited.count(x) || nums_set.count(x-1)) continue;
            auto y =x+1;
            while (nums_set.count(y))
                y++;
            ans = max(ans, y-x);
        }
        

        
        return ans;
            
        
        
        
    }
};
