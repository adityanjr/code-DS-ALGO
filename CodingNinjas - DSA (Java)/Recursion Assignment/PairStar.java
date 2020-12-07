
public class solution {

    // Return the updated string
    public static String addStars(String str) {
        // Write your code here
        if (str.length() <= 1)
            return str;

        if (str.charAt(0) == str.charAt(1))
            return str.charAt(0) + "*" + addStars(str.substring(1)); // because overlap, eg: "aaa" => "a*a*a"

        return str.charAt(0) + addStars(str.substring(1));
    }
}
