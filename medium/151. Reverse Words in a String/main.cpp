class Solution {
public:
    void reverse(string &s, int i, int j){
        while (i<j)
            swap(s[i++],s[j--]);
        
    }
    
    void write(string&s, int i, int j, int& start){
        while (i<=j)
            s[start++] = s[i++];
        s[start++] = ' ';
    }
    
    string reverseWords(string s) {
        reverse(s, 0, s.size()-1);
        int start = 0;
        for (int i= 0; true ;){
            while (i<s.size() && s[i]==' ') i++;
            int j = i;
            while (j<s.size() && s[j] != ' ') j++;
            if (i>=s.size()) break;
            reverse(s,i,j-1);
            write(s, i, j-1, start);
            i = j;
        }
        s.erase(start-1, s.size()-start+1);
        return s;
    }
};
