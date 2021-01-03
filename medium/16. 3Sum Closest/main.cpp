class Solution {
public:
    vector<int> nums;
    int target;
    int sum( int i, int j, int k){
        if (k<nums.size() && k>j) return nums[i]+nums[j]+nums[k];
        return -1e9;
    }
    int binary_search_sol(){
        sort(nums.begin(), nums.end());
        int best = -1e9;
        for (int i = 0 ; i< nums.size() ; i++){
            for (int j = i+1 ; j < nums.size() ; j++){
                int s = nums[i]+nums[j];
                int rem  = target-s;
                int k = lower_bound(nums.begin()+j+1, nums.end(), rem) - nums.begin();
                int x1 = sum(i,j,k), x2 = sum(i,j,k-1);
                
                if (abs(x1-target) < abs(best-target))
                    best = x1;
                if (abs(x2-target) < abs(best-target))
                    best = x2;
            }    
        }
        return best;
    }
    
    int two_pointers(){
        
        sort(nums.begin(), nums.end());
        int best = -1e9;
        
        for (int i = 0; i < nums.size(); i++){
            int l = i+1, r = nums.size()-1;
            int tmp_target = target-nums[i];
            while (l<r){
                int cur_sum = nums[l]+nums[r]+nums[i];
                if (abs(cur_sum-target) < abs(best-target))
                    best = cur_sum;
                if (cur_sum-nums[i] < tmp_target) l++;
                else r--;
            }
        }
        
        return best;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        this->target = target;
        this->nums = nums;
        return two_pointers();
    }
};
