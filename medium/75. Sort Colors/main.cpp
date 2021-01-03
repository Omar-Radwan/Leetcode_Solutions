class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size() ;
        int last_zero = -1, last_two = n;
        
        for (int i = last_zero+1; i< last_two;){
            if (nums[i] == 1) i++;
            else if (nums[i] == 0){
                    swap(nums[i], nums[++last_zero]);
                    if (i==last_zero)i++;
            }
            else if (nums[i] == 2){
                    swap(nums[i], nums[--last_two]);
                    if (i == last_two) i++;
            }    
        }
    }
};
