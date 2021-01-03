class Solution {
public:
    
    vector<vector<int>> ret;
    int n;
    vector<int> candidates;
    vector<vector<int>> dp;
    
    void backtrack(int i, int rem,vector<int>& subset){
        if (!solve(i, rem)) return;
        
        if (i>=n) {
            if (rem == 0) ret.push_back(subset);
            return;
        }
        
        subset.push_back(candidates[i]);
        backtrack(i, rem-candidates[i], subset);
        subset.pop_back();
        backtrack(i+1, rem, subset);
    }
    
    bool solve(int i, int rem){
        if (rem < 0) return false;
        if (i>=n) return rem==0;
        if (dp[i][rem]!=-1)  return dp[i][rem];
        return dp[i][rem] = solve(i, rem-candidates[i]) || solve(i+1, rem);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->n = candidates.size(), this->candidates = candidates;
        vector<int> subset;
        dp.resize(n, vector<int>(target+1, -1));
        solve(0, target);
        backtrack(0,target,subset);
        return ret;
    }
};
