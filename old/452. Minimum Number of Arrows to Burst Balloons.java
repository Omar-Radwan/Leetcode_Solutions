class Solution {
    public int findMinArrowShots(int[][] points) {

        int n = points.length;

        Arrays.sort(points, Comparator.comparingInt(x -> x[0]));

        int count = 0 ;

      for (int i = 0; i < n ;){
          int l = points[i][0];
          int r = points[i][1];
          count++;

          int j = i+1;
          while (j<n){
             l = Math.max(l,points[j][0]);
             r = Math.min(r,points[j][1]);
             if (r<l) break;
             j++;
          }
          i = j ;
      }




        return count;




    }
}
