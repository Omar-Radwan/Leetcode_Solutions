class Solution {
public:
    const int WATER = 0, LAND = 1;
    vector<int> di{0,0,-1,1};
    vector<int> dj{-1,1,0,0};
    vector<vector<int>> grid;
    int n,m;
    int dfs(int i, int j){
        if (i < 0 || j<0 || i>=n || j>= m || grid[i][j] == WATER) return 0;
        grid[i][j] = WATER;
        int ret = 1 ;
        for (int k = 0; k < dj.size() ; k++)
            ret+= dfs(i+di[k], j+dj[k]);
        
        return ret;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        this->grid = grid;
        this->n = grid.size(), this->m = grid[0].size();
        int maxi = 0 ;
        for (int i= 0; i < n ; i++)
            for (int j = 0 ; j < m ; j++)
                maxi = max(maxi, dfs(i,j));
            
        return maxi;
    }
};
