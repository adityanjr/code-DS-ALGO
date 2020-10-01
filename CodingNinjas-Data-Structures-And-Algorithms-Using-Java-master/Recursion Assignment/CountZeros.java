
public class solution {

    public static int countZerosRec(int num){
        // Write your code here
        if(num == 0)
            return 0;

        if(num %10 ==0)
            return 1 + countZerosRec(num / 10);
        else
            return countZerosRec(num/10); 


    }
}
