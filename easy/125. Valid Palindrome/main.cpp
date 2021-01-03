class Solution {
public:
    bool isPalindrome(string s) {
        int l= 0, r = s.size()-1;
        bool good = true;
        while (l<r && good){
            while (l<r && !isalnum(s[l])) l++;
            while (r>l && !isalnum(s[r])) r--;
            if (l<r && tolower(s[l]) != tolower(s[r]))
                    good = false;
            l++,r--;
        }
        
        return good;
    }
};
