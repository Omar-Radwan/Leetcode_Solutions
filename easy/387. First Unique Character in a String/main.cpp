class Solution {
public:
    int visited_once, visited_twice;
    
    bool is_on(int index_in_mask, int& mask){
        int test_bit = 1<<index_in_mask;
        return (test_bit & mask) != 0;
    }
    
    void turn_on(int index_in_mask, int& mask){
        mask|=(1<<index_in_mask);
    }
    
    void visit(char c){
        if (is_on(c-'a', visited_twice)) return;
        if (!is_on(c-'a', visited_once)) turn_on(c-'a', visited_once);
        else turn_on(c-'a', visited_twice);   
    }
    
    int firstUniqChar(string s) {
        visited_once = 0, visited_twice = 0 ;
        for (char c: s)
            visit(c);
        for (int i = 0; i < s.size() ; i++)
            if (is_on(s[i]-'a', visited_once) && !is_on(s[i]-'a', visited_twice))
                return i;
  
        return -1;
    }
};
