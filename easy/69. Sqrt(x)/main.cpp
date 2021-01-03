class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l<r){
            int m = l+(1LL*r-l+1)/2;
            if (1LL*m*m - x <= 0  )
                l = m;
            else r = m-1;
        }
        return l;
    }
};
