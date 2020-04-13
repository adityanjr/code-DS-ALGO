//  https://www.interviewbit.com/problems/wave-array/

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
 
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int* wave(int* A, int n1, int *len1) {
    
    int i,j;
    *len1=n1;

    qsort(A, n1, sizeof(int), cmpfunc);
    int temp;
    for(i=1;i<n1;i+=2) {
        temp=A[i];
        A[i]=A[i-1];
        A[i-1]=temp;
    }
    return A;
}

