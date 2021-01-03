class Solution {
public:

    vector<int> start_from(vector<vector<int>>& matrix, int i, int j){
        vector<int> result;
        while (i<matrix.size() && j>=0)
            result.push_back(matrix[i++][j--]);
        return result;
    }
    
    void append_vector(vector<int>& source, vector<int>& destination, int dir){
        if (dir){
            for (auto x = source.begin(); x<source.end(); x++)
                destination.push_back(*x);
        }
        else {
            for (auto x = source.rbegin(); x<source.rend(); x++)
                destination.push_back(*x);
        }
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        int dir = false;
        
        for (int i= 0; i < matrix[0].size() ; i++, dir=!dir){
            vector<int> tmp = start_from(matrix ,0,i);
            append_vector(tmp, result, dir);
        }
        
        
        for (int i= 1;  i< matrix.size() ; i++, dir=!dir){
            vector<int> tmp = start_from(matrix, i,matrix[0].size()-1);
            append_vector(tmp, result, dir);
        }
        
        return result;
                    
        
        
    }
};
