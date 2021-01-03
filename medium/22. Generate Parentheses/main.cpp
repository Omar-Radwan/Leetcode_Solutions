class Solution {
public:
    vector<string> ret;
    int n;
    void build(int i, int open, string&s){
        if (open < 0 || open > n) return;
        if (i == 2*n){
            if (open == 0)
                ret.push_back(s);
            return;
        }
        s.push_back('(');
        build(i+1,open+1,s);
        s.pop_back();
        
        s.push_back(')');
        build(i+1, open-1,s);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        this->n = n ;
        string s = "";
        build(0,0,s);
        return ret;
    }
};
