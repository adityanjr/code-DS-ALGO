// Java program to implement direct index  
// mapping with negative values allowed.  
class Mapping 
{ 
  
final static int MAX = 1000; 
  
// Since array is global, it  
// is initialized as 0.  
static boolean[][] has = new boolean[MAX + 1][2]; 
  
// searching if X is Present in  
// the given array or not.  
static boolean search(int X)  
{ 
    if (X >= 0)  
    { 
        if (has[X][0] == true)  
        { 
            return true; 
        }  
        else 
        { 
            return false; 
        } 
    } 
  
    // if X is negative take the  
    // absolute value of X.  
    X = Math.abs(X); 
    if (has[X][1] == true)  
    { 
        return true; 
    } 
  
    return false; 
} 
  
static void insert(int a[], int n)  
{ 
    for (int i = 0; i < n; i++)  
    { 
        if (a[i] >= 0)  
        { 
            has[a[i]][0] = true; 
        }  
        else 
        { 
            has[Math.abs(a[i])][1] = true; 
        } 
    } 
} 
  
// Driver code  
public static void main(String args[])  
{ 
    int a[] = {-1, 9, -5, -8, -5, -2}; 
    int n = a.length; 
    insert(a, n); 
    int X = -5; 
    if (search(X) == true) 
    { 
        System.out.println("Present"); 
    }  
    else 
    { 
        System.out.println("Not Present"); 
    } 
} 
}