class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        /*
            sum - x = k
            sum - k = x
        
        */
        long long sum = 0 ;
        unordered_map<long long, int> freq;
        freq[sum] = 1;
        int ans = 0 ;
        for (int i : nums){
            sum+= i;
            ans+= freq[sum-k];
            freq[sum]++;
        }
        
        
        return ans;
        
    }
};
