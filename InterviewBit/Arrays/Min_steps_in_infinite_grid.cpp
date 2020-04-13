//  https://www.interviewbit.com/problems/min-steps-in-infinite-grid/


/**
 * @input X : Integer array corresponding to the X co-ordinate
 * @input n1 : Integer array's ( X ) length
 * @input Y : Integer array corresponding to the Y co-ordinate
 * @input n2 : Integer array's ( Y ) length
 *
 * Points are represented by (X[i], Y[i])
 * 
 * @Output Integer
 *
 */
int coverPoints(int* X, int n1, int* Y, int n2) {
    int diffx=0;
    int diffy=0;
    int steps=0;
    int i;
    for(i=0;i<(n1-1);i++) {
        diffx=abs(X[i+1]-X[i]);
        
        diffy=abs(Y[i+1]-Y[i]);
        
        if(diffx<diffy)
            steps=steps+diffy;
        else
            steps=steps+diffx;
    }
    return steps;
}

