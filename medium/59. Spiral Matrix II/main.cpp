class Solution {
public:
    
vector<vector<int>> matrix;
    void right(int row, int start_column, int end_column, int& n){
       for (int i = start_column; i<= end_column ; i++)
            matrix[row][i] = n++;

    }
    void left(int row, int start_column, int end_column, int& n){
         for (int i = end_column; i>= start_column ; i--)
            matrix[row][i] = n++;
    }
    void down(int column, int start_row, int end_row, int& n){
      for (int i = start_row ; i<= end_row ; i++)
          matrix[i][column] = n++;
      
    }
    void up(int column, int start_row, int end_row, int& n){
        for (int i = end_row ; i>=start_row ; i--)
          matrix[i][column] = n++;
      
    }

    
vector<vector<int>> generateMatrix(int n) {
  matrix.assign(n, vector<int>(n, 0));
  int x = 1;
  int start_row = 0, end_row = n-1, start_column = 0, end_column = n-1;
  

  while (start_row <= end_row && start_column <= end_column){
       right(start_row, start_column, end_column, x);
       start_row++;

   if (start_row <= end_row && start_column <= end_column){
       down(end_column, start_row, end_row, x);
       end_column--;
   }
    
    if (start_row <= end_row && start_column <= end_column){
      left(end_row, start_column, end_column, x);
      end_row--;
    }
    
     if (start_row <= end_row && start_column <= end_column){
       up(start_column, start_row, end_row, x);
       start_column++;
     }
    
 }
  
  return matrix;
  
}


};
