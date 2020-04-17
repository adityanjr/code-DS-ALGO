//  https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/

int Solution::fibsum(int A) {
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);
    
    for(int i=2;;i++) {
        int next_fib = fib[i-1] + fib[i-2];
        if(next_fib > A)
            break;
        fib.push_back(next_fib);
    }
    
    int count = 0;
    int i = fib.size()-1;
    while(A>0) {
        while(A < fib[i])
            i--;
        A = A - fib[i];
        count++;
    }
    return count;
}

