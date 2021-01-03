class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        nums.push_back(INT_MAX);
        while (l<r){
            int m = l+(r-l)/2;
            if (nums[m]>=target) r = m ;
            else l = m+1;
        }
        return l;
    }
};
