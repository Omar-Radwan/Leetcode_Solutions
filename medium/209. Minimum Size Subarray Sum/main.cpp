class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int l = 0, r = 0, sum =0, mini = 1e9;
        while (r<nums.size()){
            while (r<nums.size() && sum< s)
                sum+= nums[r++];
            while (l < nums.size() && sum>=s)
                mini = min(mini, r-l),sum-=nums[l++];
        }
        
        return mini == 1e9? 0: mini;      
    }
};
