class Solution {
public:
    
    
    /*
        base cases:
                    (i==n-1 && j==m-1) -> 1
                    (n<=i || m <=j || g[i][j] == 1) -> 0
                    dp[i][j] = dp[i+1][j] + dp[i][j+1]; --> dp[j] = dp[j]+dp[j+1];
        
        recurrence:
    
    
    */
    vector<vector<int>> g ;
    int m,n;
    
    int bottom_up(){
        vector<vector<long long>> dp(2, vector<long long>(n+1, 0));
        
        dp[m&1^1][n-1] = g[m-1][n-1] ==0? 1:0;
        for (int i= m-1 ; i>= 0 ;i--){
            int cur = i&1, nxt = i&1^1;
            for (int j = i==m-1?n-2:n-1  ; j>=0 ; j--){
                if (g[i][j] == 1){
                    dp[cur][j] = 0;
                    continue;
                }
                dp[cur][j] = dp[nxt][j]+dp[cur][j+1];
            }
        }
        
        return dp[0][0];
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        this->g = obstacleGrid;
        this->m = obstacleGrid.size();
        this->n = obstacleGrid[0].size();
        return bottom_up();
    }
};
