class Solution {
public:
    long long reverse_int(long long x){
        long long ret = 0;
        while (x>0){
            ret+=(x%10);
            x/=10;
            if (x>0)
            ret*=10;
        }
        return ret;
        
    }
    bool isPalindrome(int x) {
        if (x<0) return false;
        return (long long)x-reverse_int(x)==0;
    }
};
