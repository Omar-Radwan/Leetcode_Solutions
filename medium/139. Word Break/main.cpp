class Solution {
public:
    unordered_set<string> a;
    string s;
    vector<int> dp;
    bool solve(int l){
        if (l>=s.size()) return true;
        int & ret =dp[l];
        if (ret!=-1) return ret;
        ret =0;
        string built_string = "";
        for (int i = l ; i < s.size() && !ret; i++)
            built_string+=s[i], ret|=(a.count(built_string)?solve(i+1):false);
        return ret;
    }
    
    bool bottom_up(){
        dp.assign(s.size()+1,0);
        dp[s.size()] = 1;
        
        for (int i= s.size()-1; i>=0 ; i--){
            string built = "";
            for (int j = i ; j<s.size() ; j++){
                built+=s[j];
                dp[i]|= a.count(built) ? dp[j+1]:false;
            }    
        }
        return dp[0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         this->s = s;
        for (string x: wordDict)
            a.insert(x);
        // dp.assign(s.size(),-1);
        return bottom_up();
        
    }
};
