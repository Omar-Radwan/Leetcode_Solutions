class Solution {
public:
    
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ret(nums.size(), -1 );
        stack<int> st;
        
        for (int i= 0; i < nums.size(); i++){
            while (!st.empty() && nums[i] > nums[st.top()]){
                ret[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        
        
        for (int i= 0; i < nums.size(); i++){
            while (!st.empty() && nums[i] > nums[st.top()]){
                ret[st.top()] = nums[i];
                st.pop();
            }
            if (ret[i]==-1)
            st.push(i);
        }
        
        return ret;

    }
};
