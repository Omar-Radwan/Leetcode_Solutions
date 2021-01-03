class Solution {
public:
    
    int bottom_up(vector<int>& nums){
        vector<int>dp(3,  0);
        for (int i = nums.size()-1; i>=0; i--)
            dp[i%3] = max(nums[i]+dp[(i+2)%3], dp[(i+1)%3]);
        return dp[0];
    }
    
    
    int rob(vector<int>& nums) {
        return bottom_up(nums);
    }
};
