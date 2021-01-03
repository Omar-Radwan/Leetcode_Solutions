class Solution {
public:
    vector<int> dr{0,0,-1,1};
    vector<int> dc{-1,1,0,0};
    const int VISITED = 65536;
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int old_color){
        if (image[sr][sc] != old_color) return;
        image[sr][sc] = VISITED;
        for (int i = 0 ;i < dr.size() ; i++){
            int nr = sr+dr[i],nc = sc+dc[i];
            if (nr>=image.size()|| nr<0 || nc >= image[nr].size() || nc<0) continue;
            dfs(image, nr, nc, newColor, old_color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image, sr, sc, newColor, image[sr][sc]);
        for (int i= 0; i < image.size() ; i++)
            for (int j = 0; j < image[i].size(); j++)
                if (image[i][j] == VISITED) image[i][j] = newColor;
         
        return image;
    }
};
