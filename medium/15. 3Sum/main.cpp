class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        for (int i= 0; i < n-2 ; ){
            int l = i+1, r = nums.size()-1;
            while (l<r){
                int sum = nums[l]+nums[r];
                if (sum == -nums[i]){
                    vector<int> tmp {nums[i], nums[l], nums[r]};
                    ret.push_back(tmp);
                    l++,r--;
                    while (l<r && nums[l]==nums[l-1]) l++;
                    while (l<r && nums[r] == nums[r+1]) r--;
                }
                else if (sum>-nums[i]) r--;
                else l++;
            }
            i++;
            while (i < nums.size() && nums[i] == nums[i-1]) i++;
        }
        
        return ret;
    }
};
