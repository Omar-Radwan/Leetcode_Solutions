class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size() ;
        vector<vector<int>> ret;
        for (int i = 0,j = i+1;i < n;i=j){
            int e = intervals[i][1];
            while (j<n && intervals[j][0] <= e) 
                e = max(e, intervals[j++][1]);
            ret.push_back(vector<int>{intervals[i][0], e});
        }
        
        return ret;
    }
};
