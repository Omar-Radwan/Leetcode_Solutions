class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        
        /*
            int take = 0,leave = 0;
            if (s[i]==s[j])
                take = 2+dp[i+1][j+1];
            leave = max(dp[i+1][j],dp[i][j+1])
            dp[i][j] = max(take,leave);
        
            j==i =i
        */
        
        int n= s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for (int i = 0; i <=n ; i++)dp[i][i] = 1;
        for (int i= n-1;i>=0;i--){
            for (int j= i+1;j<n;j++){
                int take = 0;
                if (s[i]==s[j])
                    take = 2+dp[i+1][j-1];
                int leave = max(dp[i+1][j],dp[i][j-1]);
                dp[i][j] = max(take,leave);
            }
        }
        
        return dp[0][n-1];
    }
};
