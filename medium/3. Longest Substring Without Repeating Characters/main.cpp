class Solution {
public:
    vector<int> last;
    
    
    int lengthOfLongestSubstring(string s) {
        last.assign(128, -1);
        
        int maxi = 0; 
        for (int j = 0, i = 0 ; j < s.size() ; j++){
            i = max(i, last[s[j]]+1);
            maxi = max(maxi, j-i+1);
            last[s[j]] = j;
        }
        
        return maxi;
    }
};
