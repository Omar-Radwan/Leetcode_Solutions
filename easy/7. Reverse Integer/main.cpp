class Solution {
public:
    int reverse(int x) {
        long long ret = 0; 
        bool negative = x<0;
        x = abs(x);
        
        while (x>0){
            ret+= (x%10);
            x/=10;
            ret*=10;
        }
        ret/=10;
        if (negative) ret*=-1;
        return ret >= INT_MIN && ret <= INT_MAX? ret:0;
    }
};
