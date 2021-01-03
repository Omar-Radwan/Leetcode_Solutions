class Solution {
    public String minWindow(String s, String t) {

        int minLength = Integer.MAX_VALUE;
        int l = -1, r = -1;

        int freqS[] = new int [200];
        int freqT [] = new int [200];

        for (int i = 0; i < t.length() ; i++){
            freqT[t.charAt(i)-'A']++;
        }

        int i = 0 , j = 0 ;




        while (i<s.length()){

            while (!areEqual(freqS,freqT)&&j<s.length()){
                freqS[s.charAt(j)-'A']++;
                j++;
            }
            if (areEqual(freqS,freqT)&&j-i<minLength){
                minLength = j-i;
                l = i ;
                r = j ;
            }
            freqS[s.charAt(i)-'A']--;
            i++;

        }

        return l>=0&&r>=0?s.substring(l,r):"";

    }


    boolean areEqual(int freqS[],int freqT[]){
        for (int i = 0; i < freqS.length ; i++)
            if (freqT[i]>freqS[i])
                return false;

        return true;
    }

}
