class Solution {
public:
    const char WATER = '0', LAND = '1';
    vector<int> di{0,0,-1,1};
    vector<int> dj{-1,1,0,0};
    vector<vector<char>> grid;
    int n,m;
    bool dfs(int i, int j){
        if (i < 0 || j<0 || i>=n || j>= m || grid[i][j] == WATER) return false;
        grid[i][j] = WATER;
        bool ret = true ;
        for (int k = 0; k < dj.size() ; k++)
            ret|= dfs(i+di[k], j+dj[k]);
        
        return ret;
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        this->grid = grid;
        this->n = grid.size(), this->m = grid[0].size();
        int ret = 0 ;
        for (int i= 0; i < n ; i++)
            for (int j = 0 ; j < m ; j++)
                ret+= dfs(i,j);
        return ret;
    }
};
