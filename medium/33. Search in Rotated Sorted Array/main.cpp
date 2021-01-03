class Solution {
public:
    vector<int> a;
   
    int find_pivot(int l, int r){
        while (l<r){
            int m = l+(r-l)/2;
            if (a[m] < a[0])
                r = m ;
            else 
                l = m+1;
        }
        return l;
    }
    
    int find(int l, int r, int target){
        while (l<r){
            int m = l+(r-l)/2;
            if (a[m] >= target)
                r = m;
            else 
                l = m+1;
        }
        return l;
    }
    
    
    int search(vector<int>& nums, int target) {
        a = nums;
        int pivot = find_pivot(0, nums.size()-1);

        int ans = -1;
        if (a[pivot] < a[0]){
            if (target >= a[0])
                ans = find(0, pivot-1, target);
            else 
                ans = find(pivot, nums.size()-1, target);   
        }
        else 
            ans = find(0, nums.size()-1, target);
        
        if (a[ans] != target) ans = -1; 
        return ans;
    }
};
