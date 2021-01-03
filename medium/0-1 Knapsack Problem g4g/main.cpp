
#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n) 
{ 
   vector<vector<int>> dp(W+1, vector<int>(n+1));
   
   
   for (int w = W;w>=0;w--){
       for (int i = n-1; i>=0;i--){
        int take =0,leave=dp[w][i+1];
        if (w+wt[i]<=W){
            take = val[i]+dp[w+wt[i]][i+1];
        }
        dp[w][i] = max(take,leave);
       }
   }
   
   return dp[0][0];
   
}
