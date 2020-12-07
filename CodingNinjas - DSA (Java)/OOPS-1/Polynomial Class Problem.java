
/* Signature of four required functions is given in the code. You can create other functions as well if you need.
*  Also you should submit your code even if you are not done with all the functions. 
*/

// Main used internally is shown here just for your reference.
/*public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int degree1[] = new int[n];
		for(int i = 0; i < n; i++){
			degree1[i] = s.nextInt();
		}
		int coeff1[] = new int[n];
		for(int i = 0; i < n; i++){
			coeff1[i] = s.nextInt();
		}
		Polynomial first = new Polynomial();
		for(int i = 0; i < n; i++){
			first.setCoefficient(degree1[i],coeff1[i]);
		}
		n = s.nextInt();
		int degree2[] = new int[n];
		for(int i = 0; i < n; i++){
			degree2[i] = s.nextInt();
		}
		 int coeff2[] = new int[n];
		for(int i = 0; i < n; i++){
			coeff2[i] = s.nextInt();
		}
		Polynomial second = new Polynomial();
		for(int i = 0; i < n; i++){
			second.setCoefficient(degree2[i],coeff2[i]);
		}
		int choice = s.nextInt();
		Polynomial result;
		switch(choice){
		// Add
		case 1: 
			 result = first.add(second);
			result.print();
			break;
		// Subtract	
		case 2 :
			 result = first.subtract(second);
			result.print();
			break;
		// Multiply
		case 3 :
			 result = first.multiply(second);
			result.print();
			break;
		}

	}
  */

  import java.util.*;
  import java.math.*;
  public class Polynomial {
  
      
      /* This function sets coefficient for a particular degree value, if degree is not there in the polynomial
       *  then corresponding term(with specified degree and value is added int the polynomial. If the degree
       *  is already present in the polynomial then previous coefficient is replaced by
       *  new coefficient value passed as function argument
      */
     
      ArrayList<Integer> polynomial;
      Polynomial(){
          polynomial=new ArrayList<Integer>();
      }
      public void setCoefficient(int degree, int coeff){
          // x+1 +25x^100      1 1 25z
          if(polynomial.size()==0)
              polynomial.add(0);
          while(polynomial.size()<degree+1)
              polynomial.add(0);
          polynomial.set(degree,coeff);
          return;
      }
       private int getCoefficient(int degree)
      {
          return polynomial.get(degree);
      }
      
      // Prints all the terms(only terms with non zero coefficients are to be printed) in increasing order of degree. 
      public void print(){
          for(int i=0;i<polynomial.size();i++)
          {
              if(polynomial.get(i)!=0)
                  System.out.print(polynomial.get(i)+"x"+i+" ");
          }
          return;
      }
      private int getsize(){
          return polynomial.size();
      }
      
      // Adds two polynomials and returns a new polynomial which has result
      public Polynomial add(Polynomial p){
          int s=Math.max(p.getsize(),polynomial.size());
          Polynomial result=new Polynomial();
         for(int i=0;i<s;i++)
          {
              if(p.getsize()>i && polynomial.size()>i)
              {
                  result.setCoefficient(i,polynomial.get(i)+p.getCoefficient(i));
              }
              else if(polynomial.size()>i)
              {
                  result.setCoefficient(i,polynomial.get(i));
              }
              else if(p.getsize()>i)
                  result.setCoefficient(i,p.getCoefficient(i));
              else
                  break;
          }
          return result;
      }
      
      // Subtracts two polynomials and returns a new polynomial which has result
      public Polynomial subtract(Polynomial p){
                  int s=Math.max(p.getsize(),polynomial.size());
          Polynomial result=new Polynomial();
          for(int i=0;i<s;i++)
          {
              if(p.getsize()>i && polynomial.size()>i)
              {
                  result.setCoefficient(i,polynomial.get(i)-p.getCoefficient(i));
              }
              else if(polynomial.size()>i)
              {
                  result.setCoefficient(i,polynomial.get(i));
              }
              else if(p.getsize()>i)
                  result.setCoefficient(i,-p.getCoefficient(i));
              else
                  break;
          }
          return result;
      }
      
      // Multiply two polynomials and returns a new polynomial which has result
      public Polynomial multiply(Polynomial p){
          Polynomial result=new Polynomial();
          Polynomial p1,p2;
          if(p.getsize()<polynomial.size())
          {
              p1=p;
              p2=this;
          }
          else
          {
          p1=this;
              p2=p;
          }
          // int s=Math.max(p.getsize(),polynomial.size());
          for(int i=0;i<p1.getsize();i++)
          {
              for(int j=0;j<p2.getsize();j++)
              {  if(result.getsize()<=i+j)
                  result.setCoefficient(i+j,p1.getCoefficient(i)*p2.getCoefficient(j));
               else
                   result.setCoefficient(i+j,result.getCoefficient(i+j)+(p1.getCoefficient(i)*p2.getCoefficient(j)));
              }
          }
          return result;
      }
  
  }
  