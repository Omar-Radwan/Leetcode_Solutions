class Solution {
public:
    vector<int> d_i{0,0,-1,1};
    vector<int> d_j{-1,1,0,0};

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0 ;
        for (int i= 0; i < n ; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 0 ) continue;
                int adj_count = 0 ;
                for (int k = 0 ; k < d_i.size() ; k++){
                    int adj_i = i+d_i[k], adj_j = j+d_j[k];
                    if (adj_i < 0 || adj_j < 0 || adj_i >= n || adj_j >= m || grid[adj_i][adj_j]==0)
                            continue;
                    adj_count++;
                }
                ans += 4 - adj_count;
            }
        }
        
        return ans;
    
    }
};
