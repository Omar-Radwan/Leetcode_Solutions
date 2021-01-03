class Solution {
public:
    vector<int> a;
    int length;
    Solution(vector<int>& nums) {
        for (auto c: nums)
            a.push_back(c);
        this->length = nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return a;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result(a.begin(), a.end());
        for (int i= 0; i < length ; i++){
            int j = i+rand()%(length-i);
            swap(result[i], result[j]);
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
