class Solution {
public:
    vector<int> a;
    vector<vector<vector<int>>>dp;
    int n;
    const int MOD = 1e9+7;
    
    int solve(int i, int spent, int consec){
        if (spent == n) return 1;
        int &ret = dp[i][spent][consec];
        if (ret!=-1) return ret;
        int roll_same = 0 ;
        if (consec < a[i])
            (roll_same = solve(i, spent+1, consec+1))%=MOD;
        
        int roll_different= 0 ;
        
        for (int j = 0; j <= 5; j++ ){
            if (j==i) continue;
            (roll_different+= solve(j, spent+1, 1))%=MOD;
        }
        
        return ret=(roll_same+roll_different)%MOD;
        
    }

    int dieSimulator(int size, vector<int>& rollMax) {
       n = size, a = rollMax;
        dp.assign(6, vector<vector<int>>(n,vector<int>(16,-1)));
        int ans = 0; 
        for (int i= 0 ; i<= 5 ; i++){
            (ans+=solve(i,1,1))%=MOD;
        }
        return ans;
    }
};
