class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = n+m-1;
        n--,m--;
        while (n>=0 && m>=0) nums1[l--] = nums1[m] >= nums2[n]? nums1[m--]:nums2[n--];
        while (m>=0) nums1[l--] = nums1[m--];
        while (n>=0) nums1[l--] = nums2[n--];
    }
};
