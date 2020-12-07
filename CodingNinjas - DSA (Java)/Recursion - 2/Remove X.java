public class solution {

    // Return the changed string
    public static String removeX(String input){
        // Write your code here
        if(input.length()<=1)
        {
            if(input.charAt(0)=='x')
            {
                return "";
            }
            else
                return input;
        }
        if(input.charAt(0)=='x')
        {
            input=input.substring(1);
            return removeX(input);
        }
        return input.charAt(0)+removeX(input.substring(1));
    }
}

