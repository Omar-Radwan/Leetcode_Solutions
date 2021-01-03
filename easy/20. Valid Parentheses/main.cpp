class Solution {
public:
    bool isValid(string s) {

        stack<char> open;
        for (char &c: s){
            if (c == '(' || c == '{' || c=='[' )
                open.push(c);
            else if (open.empty() || 
                     (c == ')' && open.top()!='(') ||
                     (c == '}' && open.top()!='{') ||
                     (c == ']' && open.top()!='[') )
                return false;
            else open.pop();
        }
        
        return open.empty();
        
    }
};
