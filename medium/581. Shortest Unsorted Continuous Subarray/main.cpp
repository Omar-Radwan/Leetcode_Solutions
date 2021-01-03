class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    
        /*
            maxi from front <= mini from back
            mini from back >= maxi from font
        
            ----|------------|-----
            
            max(prefix) <= any number after it
            min(suffix) >= any number before it
            
        */
        int n= nums.size();
        if (n==1) return 0;
        vector<int> prefix(n), suffix(n);
        prefix[0] = nums[0], suffix[n-1] = nums[n-1];
        for (int i= 1 ; i < n ; i++)
            prefix[i] = max(prefix[i-1], nums[i]);
        
        for (int i = n-2 ; i>=0 ; i--)
            suffix[i] = min(suffix[i+1], nums[i]);
        
        int maxi = nums[0], l = 0;
        while (l<nums.size()){
            maxi = max(maxi, nums[l]);
            if (l+1< n && maxi <= suffix[l+1])
                l++;
            else break;
        }
        
        int mini = nums[n-1], r= n-1;
        while (r>=0){
            mini = min(mini, nums[r]);
            if (r-1>=0 && mini >= prefix[r-1])
                r--;
            else break;
        }
        
        int size = max(r-l+1, 0 );
        return size;
            
    }
};
