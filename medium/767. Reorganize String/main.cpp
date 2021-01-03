class Solution {
public:
    string reorganizeString(string S) {
        vector<pair<int,int>> freq(26);
        int maxi = 0 ;
        for (int i= 0 ; i <freq.size() ; i++)
            freq[i] = {0,'a'+i};
        
        for (auto&c:S)
            freq[c-'a'].first++;
        
        sort(freq.begin(),freq.end(),greater<pair<int,int>>());
        
        if (freq[0].first > (S.size()+1)/2) 
            return "";
        
        S.assign(S.size(),'#');
        
        for (int i= 0, j=0 ; i < S.size(); ){
            while (j<freq.size()&&freq[j].first==0) j++;
            while (j<freq.size() && i<S.size() && freq[j].first!=0){
                S[i]= freq[j].second;
                i+=2, freq[j].first--;
            }
        }

        
        for (int i= 1, j=0 ; i < S.size(); ){
            while (j<freq.size()&&freq[j].first==0) j++;
            while (j<freq.size() && i<S.size() && freq[j].first!=0){
                S[i]= freq[j].second;
                i+=2, freq[j].first--;                
            }

        }
        
        
        return S;
        
    }
};
