public class Solution {

    public static boolean checkAB(String s) {

        if (s.length()==0) 
            return true;
        if (s.charAt(0) != 'a')
            return false;
        if (s.length() >= 3 && "abb".equals(s.substring(0,3)))
            return checkAB(s.substring(3));
        else
            return checkAB(s.substring(1));
    }
}
