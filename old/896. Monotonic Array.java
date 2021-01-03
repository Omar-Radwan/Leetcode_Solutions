class Solution {
    public boolean isMonotonic(int[] A) {

        short cur = -1;
        boolean good = true;
        for (int i = 1 ;i<A.length ; i++){
            if (cur==-1&&A[i]>A[i-1])
                cur = 1;

            else if (cur==-1&&A[i]<A[i-1])
                cur=  0 ;


            else if ((cur==1&&A[i]<A[i-1])||(cur==0&&A[i]>A[i-1])){
                good = false;
                break;
            }

        }

        return good;

    }
}
