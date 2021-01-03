class Solution {
public:
    const char X = 'X', O = 'O', VISITED = '#';
    int n, m;
    vector<int> dx  {-1,1,0,0};
    vector<int> dy  {0,0,-1,1};
    
    bool is_surrounded(int i, int j, vector<vector<char>>& a){
        if (i<0 || j<0 || i>=n || j>=m) return false;
        if (a[i][j] != O) return true;
        
        a[i][j] = VISITED;
        int result = true;
        for (int k= 0; k < dx.size() ; k++){
            int ni = i+dx[k], nj = j+dy[k];
            result&= is_surrounded(ni, nj, a);
        }
        
        return result;
    }
    
    void change_char(int i ,int j, char type, vector<vector<char>>& a){
         if (i<0 || j<0 || i>=n || j>=m) return;
        if (a[i][j] != VISITED) return;
        
        a[i][j] = type;
        
        for (int k= 0; k < dx.size() ; k++){
            int ni = i+dx[k], nj = j+dy[k];
            change_char(ni, nj, type, a);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return ;
        n = board.size(), m = board[0].size();

        for (int i= 0 ; i < n ; i++){
            for (int j = 0; j < m ; j++){
                if (board[i][j] != O) continue;
                bool surrounded = is_surrounded(i,j, board);
                if (surrounded)
                    change_char(i,j,X, board);
            }
        }
        
        
        for (int i= 0; i < n ; i++)
            for (int j = 0; j < m ; j++)
                if (board[i][j] == VISITED)
                board[i][j] = O;
            
        
        
    }
    
    
    
};
