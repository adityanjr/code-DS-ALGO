//  https://www.interviewbit.com/problems/maximum-unsorted-subarray/

vector<int> Solution::subUnsort(vector<int> &A) {
    int flag=0;
    int n = A.size();
    for(int i=1;i<n;i++)
        if(A[i]<A[i-1]) {
            flag = i;
            break;
        }
    vector<int> result;
    if(!flag) {
        result.push_back(-1);
        return result;
    }
    
    int l = flag-1, r;
    for(int j=n-1;j>0;j--)
        if(A[j]<A[j-1]) {
            r = j;
            break;
        }
    // find smallest and the largest element in the range l-r
    int smallest=A[l], largest=A[l];
    
    for(int i=l;i<=r;i++) {
        smallest = min(smallest, A[i]);
        largest = max(largest, A[i]);
    }    
    
    //cout << smallest << " " << largest << endl;
    
    
    for(int i=0;i<l;i++)
        if(A[i]>smallest) {
            l = i;
            break;
        }
    for(int j=n-1;j>r;j--)
        if(A[j]<largest) {
            r = j;
            break;
        }
    
    result = {l, r};
    return result;
}

