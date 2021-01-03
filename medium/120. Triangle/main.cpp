class Solution {
public:
    vector<vector<int>> a;
    int n;
    /*
        i>=n return 0;
        dp[i][j] = a[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
    */
    int bottom_up(){
        vector<vector<int>> dp(2, vector<int>(n+1));
        for (int i= n-1 ;i >= 0; i--){
            int cur = i&1, nxt = i&1^1;
            for (int j = a[i].size()-1 ; j>=0 ; j--)
                dp[cur][j] = a[i][j]+min(dp[nxt][j],dp[nxt][j+1]);
            
        }
        return dp[0][0];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        this->a  = triangle;
        this->n = triangle.size();
        return bottom_up();
    }
};
