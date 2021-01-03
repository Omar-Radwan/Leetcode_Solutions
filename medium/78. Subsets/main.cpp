class Solution {
public:
    vector<vector<int>> ret;
    vector<int> nums;
    void solve(int i, vector<int>& current){
        if (i >= nums.size()){
            ret.push_back(current);
            return;
        }
        
        current.push_back(nums[i]);
        solve(i+1, current);
        current.pop_back();
        solve(i+1, current);
        
    }
    
    vector<int> build_subset(int mask){
        vector<int> subset;
        for (int i= 0; i < nums.size() ; i++)
            if ((1<<i)&mask)
                subset.push_back(nums[i]);
        return subset;
    }
    void bitmask(){
        int last = 1<<nums.size();
        
        for (int i= 0; i < last ;i++){
            ret.push_back(build_subset(i));
        }
        
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        //vector<int> cur;
        //solve(0, cur);
        bitmask();
        return ret;
    }
};
