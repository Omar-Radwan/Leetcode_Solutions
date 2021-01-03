class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0 ;
        int n = num1.size()-1, m = num2.size()-1;
        string ans = "";
        while (n>=0 || m>=0){
            int v1 = n>=0 ? num1[n--]-'0':0, v2 = m>=0? num2[m--]-'0':0;
            int cur = v1+v2+carry;
            if (cur>=10)
                carry = 1, cur = cur-10;
            else carry =0;
            ans+=cur+'0';
        }
    
        ans+=carry==1? "1":"";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
