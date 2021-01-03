class Solution {
public:
    
    const int MOD = 1e9+7, P = 53, ALPHABET_SIZE = 27;
    vector<int> p, prefix;
    
    void fill_power(int n){
        p.push_back(1);
        for (int i = 1 ; i<= n ; i++)
            p.push_back((1LL*P*p[i-1])%MOD);
    }
    
    void fill_prefix(const string& s ){
        int n = s.size();
        prefix.push_back(0);
        for (int i = 1; i <= n ; i++)
            prefix.push_back((1LL*prefix[i-1] + 1LL*p[i-1]*(s[i-1]-'a'+1)) %MOD);
    }
    
    int hash_str(const string &s){
        int n = s.size(), ret = 0;
        for (int i= 0 ; i < n ; i++)
            (ret+= ((1LL*p[i]*(s[i]-'a'+1))%MOD))%=MOD;
        return ret;
    }
    
    int query(int i, int j){
        return (prefix[j+1]-prefix[i]+MOD)%MOD;
    }
    
    int modify(int i, int val){    
        return (1LL*val*1LL*p[p.size()-i-1])%MOD;
    }
    
    
    int strStr(string haystack, string needle) {
        fill_power(max((int)haystack.size(), ALPHABET_SIZE));
        fill_prefix(haystack);
        
        int n= haystack.size(), m = needle.size();
        int hneedle = hash_str(needle);
        hneedle = modify(0, hneedle);
        
        for (int i= 0, j = i+m-1; j < n ; i++, j++){
            int hstack = modify(i, query(i,j));
            if (hneedle == hstack)
                return i;
        }
        
        return -1;    
    }
};
