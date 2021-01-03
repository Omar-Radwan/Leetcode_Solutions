class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int last_inserted = -1;
        for (int i = 0 ; i< nums.size(); i++)
            if (nums[i]!=0)
                swap(nums[++last_inserted], nums[i]);
        
    }
};
