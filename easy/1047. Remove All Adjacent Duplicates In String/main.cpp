class Solution {
public:
    string removeDuplicates(string s) {
        string ret;
        for (char& c: s){
            if (ret.back() == c) ret.pop_back();
            else ret.push_back(c);
        }
        return ret;
    }
};
