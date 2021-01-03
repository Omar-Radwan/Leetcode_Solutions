class Solution {
public:

    const int x = 53, MOD = 1e9+7;
    vector<int> p;
    
    void fill_power(const int & n){
        p.push_back(1);
        for (int i= 1 ; i<=n ; i++)
            p.push_back((1LL*p[i-1] * x) %MOD);
    }
    
    int no_order_hash(const string & s){
        int ret = 0 ;
        for (char c: s)
            (ret+= 1LL*p[c-'a'+1])%=MOD;
        return ret;
    }
    
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        fill_power(50);
        vector<pair<int,int>> v;
        
        int i = 0;
        for (string & s: strs){
            int hash = no_order_hash(s);
            v.push_back({hash, i});
            i++;
        }
 
        sort(v.begin(), v.end());
        
        for (int i= 0 ; i < v.size(); i++){
            if (i==0 || v[i].first != v[i-1].first)
                ret.push_back(vector<string>());
            ret.back().push_back(strs[v[i].second]);
        }

        return ret;
    }
};
