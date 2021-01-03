class Solution {
public:
    vector<int> dp;
    int m,n;
    
    int bottom_up(){
        dp.assign(n+1, 0);
        dp[n-1] = 1;     
        for (int i = m-1;  i>= 0; i--)
            for (int j = n-1 ; j>= 0; j--)
                dp[j] = dp[j]+dp[j+1];
        
        return dp[0];
    }
    int uniquePaths(int m, int n) {
        this->m = m, this->n = n ;
        return bottom_up();
    }
};
