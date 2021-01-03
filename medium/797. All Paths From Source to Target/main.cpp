class Solution {
public:
    vector<vector<int>> ans,  g;
    int n;
    void backtrack(int node, vector<int>& path){
        
        path.push_back(node);
        
        if (node == n-1) {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for (int v: g[node])
            backtrack(v, path);
        
        path.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        g = graph;
        vector<int> v;
        backtrack(0, v);
        return ans;
    }
};
