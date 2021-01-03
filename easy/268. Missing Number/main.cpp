class Solution {
public:
    int summation(int n){
        return n*(n+1)/2;
    }
    int gauss(vector<int>& nums){
        int sum = 0 ;
        for (int i= 0; i < nums.size(); i++)
            sum+= nums[i];
        return summation(nums.size())-sum;
    }
    int xor_solution(vector<int>& nums){
        int ans = nums.size() ;
        for (int i= 0 ; i< nums.size();i++)
            ans^=i^nums[i];
        return ans;    
    }
    int missingNumber(vector<int>& nums) {
        return xor_solution(nums);
    }
};
