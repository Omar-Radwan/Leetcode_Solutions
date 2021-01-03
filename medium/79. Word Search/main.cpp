class Solution {
public:
    
    
    const vector<int> delta_i{0,0,1,-1};
    const vector<int> delta_j{-1,1,0,0};
    
        int solve(int i, int j, int l,string&s, vector<vector<bool>> & visited, vector<vector<char>>& board, string& word){
        if (l==word.size()) return true;
            
        if (i<0 || j < 0 || i >= board.size()|| j >=board[0].size() || visited[i][j]|| board[i][j]!=word[l]) return false; 
            
        bool ret = false;
            
        s.push_back(board[i][j]),visited[i][j] = true;
            
        for (int k= 0; k < delta_i.size() && !ret; k++){
            int new_i = i+delta_i[k], new_j = j+delta_j[k];
            ret|=solve(new_i, new_j,l+1 ,s, visited, board, word);            
        }
            
        s.pop_back(),visited[i][j] = false;
        return ret;
        
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        string dummy = "";
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
        for (int i = 0; i < board.size() ; i++)
            for (int j= 0; j < board[0].size() ; j++)
                if (solve(i,j,0,dummy,visited,board,word))
                    return true;
        return false;
    }
};
