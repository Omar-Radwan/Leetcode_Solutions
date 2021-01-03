class Solution {
public:
    vector<int> coins;
    int amount;
    
    int bottom_up(){
        vector<int> dp(amount+5, 0);
        for (long long val = amount-1; val>=0 ; val--){
            int mini = 1e9;
            for (int i= coins.size()-1; i>=0 ; i--)
                if (val+coins[i] <= amount)
                    mini = min(mini, dp[val+coins[i]]);
            dp[val] = 1+mini;
        }
            
        
        return dp[0] >= 1e9? -1:dp[0];
        
    }
    int coinChange(vector<int>& coins, int amount) {
        this->coins = coins;
        this->amount = amount;
        return bottom_up();
    }
};
