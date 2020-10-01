
public class solution {

    public static boolean isStringPalindrome(String input) {
        // Write your code here
        for (int i = 0; i < input.length() / 2; i++)
            if (input.charAt(i) != input.charAt(input.length() - i - 1))
                return false;
        return true;
    }
}
