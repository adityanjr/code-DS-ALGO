//  https://www.interviewbit.com/problems/count-element-occurence/

int findIndex(const vector<int> &A, int B) {
    int l=0, r = A.size()-1;
    int index = -1;
    while(l<=r) {
        int m = l+(r-l)/2;
        if(A[m]==B) {
            while(A[m]==B)
                m--;
            index = m+1;
            break;
        }
        else if(A[m]>B)
            r = m-1;
        else 
            l = m+1;
    }
    return index;
}
int Solution::findCount(const vector<int> &A, int B) {
    int index = findIndex(A, B);
    if(index == -1)
        return 0;
    int count = 0;
    while(A[index]==B && index<A.size()) {
        index++;
        count++;
    }
    return count;
}

