class Solution {
public:
    
    double fast_pow(double x, long long n ){
        if (n==0) return 1;
        if (n&1)
            return x*fast_pow(x,n-1);
        double tmp = fast_pow(x,n/2);
        return tmp*tmp;
    }
    
    double myPow(double x, int n) {
        if (n < 0){
            return 1/fast_pow(x,-1LL*n);
        }
        return fast_pow(x,n);
    }
};
