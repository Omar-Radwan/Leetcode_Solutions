class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        
        for (int i= 0; i < nums2.size() ; i++){
            while (!st.empty() && st.top() < nums2[i]){
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        for (int& x: nums1){
            if (!mp.count(x)) x = -1;
            else x = mp[x];
        }
        return nums1;
    }
};
