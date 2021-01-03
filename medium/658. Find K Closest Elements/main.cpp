class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int  r = lower_bound(arr.begin(),arr.end(),x)-arr.begin(), l = r-1;
        
        while (l>=0 && r<arr.size() && k--){
            if (abs(arr[l]-x)<=abs(arr[r]-x)) l--;
            else r++;
        }
        
        while (l>=0 && k-->0) l--;
        while (r<arr.size() && k-->0) r++;
        l++,r--;
  
        vector<int> ret;
        while (l<=r) ret.push_back(arr[l++]);
        return ret;
    }
};
