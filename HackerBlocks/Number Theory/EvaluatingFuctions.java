import java.util.*;
import java.util.Scanner;
import java.math.BigInteger;

public class EvaluatingFuctions {

    public static void main(String args[]) {
         Scanner sc = new Scanner(System.in);
		 BigInteger b2,b3,B;
         String s  = sc.next();
		 BigInteger b = new BigInteger(s);
         b2 = b.multiply(b);
		 b3 = b2.multiply(b);
         
		 b = b.multiply(BigInteger.valueOf(6));
		 b2 = b2.multiply(BigInteger.valueOf(5));
		 b3 = b3.multiply(BigInteger.valueOf(4));

		 B= b2;
		 B= B.add(b3);
		 B= B.subtract(b);
		 B= B.add(BigInteger.valueOf(14));
		 
		 System.out.println(B);
    }
}