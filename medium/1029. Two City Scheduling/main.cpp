class Solution {
public:
    int n;
    const int INF = 1e9;

    int bottom_up(vector<vector<int>>& c){
        int n = c.size()/2;
        vector<int> dp(n+2, INF);
        dp[n] = 0;
        for (int i= 2*n-1; i>= 0; i--){
            int mini = min(n,i);
            for (int a = 0; a<= mini ; a++)
                dp[a] = min(dp[a+1], c[i][1]+dp[a]);           
        }
        return dp[0];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        return bottom_up(costs);      
    }
};
