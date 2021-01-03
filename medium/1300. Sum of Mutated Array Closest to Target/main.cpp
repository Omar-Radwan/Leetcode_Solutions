class Solution {
public:
    vector<int> a;
    
    int test(int v){
        int sum = 0 ;
        for (auto&x:a)
            sum+= x>=v? v:x;
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        a  =arr;
        int maxi = 0 ;
        for (int i= 0; i < arr.size(); i++){
            maxi = max(maxi, arr[i]);
        }
        int l = 0, r = maxi;
        
        while (l<r){
            int m = l+(r-l)/2;
            if (test(m)>=target)
                r = m ;
            else 
                l = m+1;
        }
    
        int v1 = test(r),v2 = test(r-1);
        if (v1-target<target-v2)
            return min(r,maxi) ;
        else return r-1;
        
    }
};
