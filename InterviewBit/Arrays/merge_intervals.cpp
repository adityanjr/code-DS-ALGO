//  https://www.interviewbit.com/problems/merge-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(Interval a, Interval b) {
    return a.start<b.start;
} 

vector<Interval> Solution::insert(vector<Interval> &A, Interval B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    A.push_back(B);
    sort(A.begin(), A.end(), comp);
    
    vector<Interval> result;
    Interval temp = A[0];
    int i = 0, n = A.size();
    for(int j=1;j<n;j++) {
        if(temp.end >= A[j].start)
            temp.end = max(temp.end, A[j].end);
        else {
            result.push_back(temp);
            temp = A[j];
        }
    }
    result.push_back(temp);
    return result;
}

