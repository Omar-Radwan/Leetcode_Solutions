class Solution {
public:
    
    
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        
        for (char c: s){
            if (st.empty())
                st.push({c,1});
            else {
                if (st.top().first == c){
                    pair<char,int> t = st.top();
                    st.pop();
                    t.second++;
                    if (t.second < k )st.push(t);
                }
                else {
                    st.push({c,1});
                }
            }
        }
        
        string ret = ""; 
        while (!st.empty()){
            pair<char,int> t = st.top();
            st.pop();
            string tmp(t.second,t.first);
            ret+=tmp;
        }
        
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
