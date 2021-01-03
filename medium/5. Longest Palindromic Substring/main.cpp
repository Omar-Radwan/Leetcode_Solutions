class Solution {
public:
    string s;
    int n;
    pair<int,int> expand(int l, int r){
        while (l-1>=0 && r+1< n && s[l-1] == s[r+1]) l--,r++;
        return pair<int,int>(l,r);
    }
    int length(int l, int r){
      return r-l+1;  
    } 
    
    string longestPalindrome(string s) {
        this-> s = s,n = s.size();
        int bl = 0 ,br = 0;
        for (int i= 0; i < s.size() ; i++){
            
            auto [l1,r1] = expand(i,i);
            if (length(l1,r1)>length(bl,br)) bl = l1, br = r1;
            
            if (i+1 < n && s[i] == s[i+1]){    
                auto [l2,r2] = expand(i,i+1);
                if (length(l2,r2)>length(bl,br)) bl = l2, br = r2;
            }
            
        }
        
        return s.substr(bl, br-bl+1);
    }
};
