class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 1, prev2 = 1, current= 1 ;
        for (int x = 2 ; x<=n ; x++)
            current = prev1+prev2, prev2 = prev1, prev1= current;
        
        return current;
    }
};
