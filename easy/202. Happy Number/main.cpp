class Solution {
public:
    int f(int x){
        int ret = 0 ;
       while (x>0){
           int last = x%10;
           x/=10;
           ret+= last*last;
       } 
        return ret;
    }
    bool isHappy(int n) {
        unordered_set<int> visited;
        while (n>1){
            visited.insert(n);
            n = f(n);
            if (visited.count(n)) return false;
        }
        return true;
    }
};
