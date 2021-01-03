class Solution {
public:
    string s;
    int n ;
    vector<int> dp;
    int top_down(int i){
        if (i>=n) return 1;
        int one=0 , two=0;
        int &ret = dp[i]; if (ret!=-1)  return ret;
        ret = 0 ;
        if (
            i+1 < n &&
            ((s[i]=='1' && s[i+1] <='9')|| 
             (s[i]=='2' && s[i+1]<='6'))
            )
            two = top_down(i+2);
        
        if (s[i]!='0')
            one = top_down(i+1);
        
        return ret = one+two;
    }
    
    int bottom_up(){
        dp.assign(3, 0);
        dp[n%3] = 1;
        for (int i= n-1 ; i>= 0 ; i--){
            int one = 0, two = 0 ;
            if (s[i]!='0') 
                one = dp[(i+1)%3];
            
           if (i+1 < n  &&
            ((s[i]=='1' && s[i+1] <='9')|| 
            (s[i]=='2' && s[i+1]<='6'))) 
                two = dp[(i+2)%3];
            
            dp[i%3] = one+two;
        }
        return dp[0];
    }
    
    
    int numDecodings(string s) {
        this->s = s;
        this-> n = s.size();
        //dp.assign(n,-1); 
        return bottom_up();
    }
};
