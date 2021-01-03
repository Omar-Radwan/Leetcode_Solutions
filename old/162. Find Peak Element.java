class Solution {
    public int findPeakElement(int[] nums) {


        for (int i = 0; i < nums.length ; i++){
            boolean good = true;
            if (i>0&&nums[i-1]>nums[i]) good = false;
            if (i+1<nums.length&&nums[i+1]>nums[i]) good= false;
            if (good) return i ;
        }

        return -1;
    }
}
