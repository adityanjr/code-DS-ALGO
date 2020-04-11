//  https://www.interviewbit.com/problems/merge-overlapping-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
int comp(Interval a, Interval b) {
    return a.start < b.start;
} 

vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    
    vector<Interval> result;
    int n = A.size();
    if(n==1)
        return A;
    //cout << n << endl;
    
    sort(A.begin(), A.end(), comp);
    
    Interval pair;
    pair.start = A[0].start;
    pair.end = A[0].end;
    
    int i = 1;
    while(1) {
        if(max(pair.start, A[i].start) > min(pair.end, A[i].end)) {
            result.push_back(pair);
            pair.start = A[i].start;
            pair.end = A[i].end;
        }
        else {
            pair.end = max(pair.end, A[i].end);
        }
        i++;
        if(i>=n)
            break;
    }
    result.push_back(pair);
    return result;
}



################# OR ####################
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool myComp(Interval a, Interval b) {
    return a.start < b.start;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size()<2)
        return A;
    
    sort(A.begin(), A.end(), myComp);
    vector<Interval> result;
    Interval temp = A[0];
    
    for(int j=1;j<A.size();j++) {
        // overlaps
        if(temp.end >= A[j].start) {
            temp.end = max(temp.end, A[j].end);
        }
        // no overlap
        else {
            result.push_back(temp);
            temp = A[j];
        }
        
    }
    result.push_back(temp);
    return result;
}


