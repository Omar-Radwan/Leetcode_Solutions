class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        vector<int> ret(T.size(), 0);
        int i= 0 ;
        for (int x: T){
            while (!st.empty() && T[st.top()] < x){
                
                ret[st.top()] = i-st.top(), st.pop();
            }
            
            st.push(i++);
        }
        
        return ret;
    }
};
