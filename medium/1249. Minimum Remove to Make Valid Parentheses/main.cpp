class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open=0;
        for (auto&c:s){
            if (c==')'){
                if (open<=0)
                    c = '*';
                else open--;
            }
            else if (c=='(')
                open++;
        }
        
        for (int i= s.size()-1; i>=0;i--){
            auto&c =s[i];
            if (open==0) break;
            if (c=='(')
                c='*',open--;
        }
        string ret="";
        for (auto&c:s)
            if (c!='*')
                ret+=c;
        return ret;
    }
};
