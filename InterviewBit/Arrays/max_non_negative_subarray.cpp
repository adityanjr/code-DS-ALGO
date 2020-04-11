//  https://www.interviewbit.com/problems/max-non-negative-subarray/

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in length_of_array
 */
int* maxset(int* A, int n1, int *length_of_array) {
    /*
     * Sample Code : 
     *  *length_of_array = 1;
     *  int * ret = (int *) malloc(sizeof(int) * *length_of_array);
     *  ret[0] = 1;
     *  return ret;
     */
     int i=0;
     *length_of_array = n1;
     int *range = (int*)malloc(sizeof(int)* *length_of_array);
     long long max = 0;
     long long sum=0;
     int count=0;
     int maxCount=0;
     int startIdx=0;
     for(i=0;i<n1;i++) {
         
         if(A[i]>=0) {
             sum = sum + (long long)A[i];
             count++;
             if(i==n1-1) {
                 if(max<sum || (max==sum && count>maxCount)) {
                     max = sum;
                     maxCount = count;
                     memcpy(range,A+startIdx,sizeof(int)*maxCount);
                }
             }
         }
         
         else {
             if(max<sum || (max==sum && count>maxCount)) {
                    max = sum;
                    maxCount = count;
                    memcpy(range,A+startIdx,sizeof(int)*maxCount);
             }
             sum = 0;
             count = 0;
             startIdx = i+1;
             //*length_of_array = maxCount;
         }
     }
     *length_of_array = maxCount;
     return range;
}

