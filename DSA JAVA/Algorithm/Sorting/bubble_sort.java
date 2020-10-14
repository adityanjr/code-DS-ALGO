// BUBBLE SORT
import java.util.Scanner;

class bubble_sort{
    public static void main(String args[]){

    int n,change;
	int p[] = new int[30];
    Scanner sc= new Scanner(System.in);
    System.out.println("enter length of array::");
    n=sc.nextInt(); // take the length of array
    System.out.println("\n enter array elements here::");
    for(int i=0;i<n;i++) //take elements here
    {
        p[i]=sc.nextInt();
    }
    for(int pass=1;pass<n-1;pass++)  // now sorting process is started
    {
        change=0;
        for(int i=0;i<(n-pass);i++)
        {
            if(p[i]>p[i+1])
            {
                int temp = p[i];
                p[i] = p[i+1];
                p[i+1] = temp;
                change++;
            }
        }
    }
    // print the sorted elements
    System.out.println("\n================================\n");
    for(int i=0;i<n;i++)
    {
        System.out.println(p[i]);
    }
    }
}