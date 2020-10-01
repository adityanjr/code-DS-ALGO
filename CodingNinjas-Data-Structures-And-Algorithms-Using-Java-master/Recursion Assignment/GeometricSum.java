import  java.lang.Math.*;
public class solution {

	public static double findGeometricSum(int n){
	if(n==0)
		{
			return 1;
		}
	return 1+ 0.5*(findGeometricSum(n-1));
    }
    }