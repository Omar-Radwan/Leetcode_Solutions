class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        if (matrix==null||matrix[0]==null) return 0 ;
        int n  = matrix.length;
        int m = matrix[0].length;

        for (int i= 0 ; i< n ; i++){
            for (int j = 0 ; j < m ; j++){
                matrix[i][j] +=i>0? matrix[i-1][j]:0;
                matrix[i][j]+=j>0 ?matrix[i][j-1]:0;
                matrix[i][j]-= i>0&&j>0? matrix[i-1][j-1]:0;
            }
        }

        int count = 0 ;


        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                for (int l = i ; l<n ; l++){
                    for (int k = j ; k < m ; k++){
                        int sum = matrix[l][k];
                        sum-=i>0? matrix[i-1][k]:0;
                        sum-=j>0? matrix[l][j-1]:0;
                        sum+=i>0&&j>0? matrix[i-1][j-1]:0;
                        if (sum==target){
                            count++;
                        }
                    }
                }
            }
        }

        return count;








    }
}
