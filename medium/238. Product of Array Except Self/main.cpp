class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     
      vector<int> result(nums.size(), 1);
      int prefix_product = 1;

      for (int i = nums.size()-2 ; i>=0; i--)
         result[i] = nums[i+1]*result[i+1];



      for (int i = 0; i < nums.size() ; i++){
          result[i]*= prefix_product;
          prefix_product*=nums[i];
      }

      return result;
        
    }
};
