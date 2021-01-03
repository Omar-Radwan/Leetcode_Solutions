class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor_result = 0;
        for (int &x: nums)
            xor_result^= x;
    
        return xor_result;
    }
};
