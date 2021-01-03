class Solution {
public:
    unordered_map<int,int> mp;
    string rep(int cnt, string& s){
        string result = "";
        while (cnt--)
            result+=s;
        return result;
    }
    int repetitions(int i, string&s){
        int j = i-1;
        string x = "";   
        while (j>=0 && s[j]>='0'&&s[j]<='9')
            x+=s[j],j--;
        reverse(x.begin(),x.end());

        return stoi(x);
    }
    string decode_string(int l, int r,string& s){

        string result = "";
        for (int i= l; i<r;){
            if (s[i]=='['){
                string tmp = decode_string(i+1,mp[i], s );
                result+=rep(repetitions(i,s), tmp);
                i = mp[i]+1;    
            }else{
                if (isalpha(s[i]))
                result+=s[i];
                i++;
            } 
        }
        return result;
    }

    string decodeString(string s) {
        s = s;
        stack<int> st;
        int i= 0; 
        for (auto&c:s){
            if (c=='[')
                st.push(i);
            else if (c==']'){
                mp[st.top()]=i; 
                st.pop();
            }
            i++;
        }
        return decode_string(0, s.size(),s);
    }
};
