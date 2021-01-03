class Solution {
public:
    int expand(string&s, int i, int j){
        int result = 0 ;
        while (i>=0 && j<s.size() && s[i--]==s[j++])
            result++;
        return result;     
    }
    int countSubstrings(string s) {
        int result = 0 ;
        for (int i = 0; i < s.size(); i++)
            result+= expand(s, i, i)+ (i+1< s.size()? expand(s,i,i+1):0);
        
        return result;
    }
};
