class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
 
 
        int min_length = INT_MAX;
        for (string &s: strs)
            min_length = min(min_length,(int)s.size());
 
        string lcp = "";       
        for (int i = 0; i < min_length ; i++){
            bool good = true;
            for (int j = 1 ; j < strs.size() && good; j++){
                if (strs[j][i] != strs[0][i]) good = false;
            }
            if (good) lcp+= strs[0][i];
            else break;
        }
        return lcp;
    }
};
