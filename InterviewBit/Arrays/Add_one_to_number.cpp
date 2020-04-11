//  https://www.interviewbit.com/problems/add-one-to-number/

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */
int* plusOne(int* A, int n1, int *len1) {
    int i,dig,carry=1,len=0;
    int *out = (int *)malloc(sizeof(int)*(n1+1));
    int oind = n1;
    for(i=n1-1;i>=0;i--){
        out[oind--] = (A[i]+carry)%10;
        carry = (A[i]+carry)/10;
    }
    out[oind] = carry;
    for(i=0;i<n1+1&&out[i]==0;i++)
        len++;
    out = out+len;
    *len1=n1+1-len;
    return out;
}

