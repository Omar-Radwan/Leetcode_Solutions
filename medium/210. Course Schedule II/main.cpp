class Solution {
public:
    
    const int UNVISITED=0, PROCESSING=1, VISITED=2;
    vector<vector<int>> g;
    vector<int> state;
    vector<int> result_vector;
    
    bool dfs(int u){
        if (state[u] == PROCESSING) return false;
        if (state[u] == VISITED) return true;
        bool ret = true;
        state[u] = PROCESSING;
        for (auto&v: g[u])
            ret &= dfs(v);
        state[u] = VISITED;
        result_vector.push_back(u);
        return ret;
    }
    
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        g.resize(numCourses);
        state.resize(numCourses, 0);
        for (auto& x: prerequisites)
            g[x[0]].push_back(x[1]);
        
        bool result = true;
        for (int u = 0; u < numCourses; u++)
            result&=dfs(u);
    
        
        
        return  (result?  result_vector: vector<int>());
    }
};
