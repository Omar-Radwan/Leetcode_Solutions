class Solution {
public:
    int minAddToMakeValid(string S) {
     int open = 0,sum=0;
        for (auto&c:S){
            if (c=='(')
                open++;
            
            else {
              if (open<=0)
                  sum++;
              else open--;
            }
        }
        sum+=open;
        return sum;
    }
};
