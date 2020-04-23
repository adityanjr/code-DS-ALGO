// https://www.interviewbit.com/problems/rain-water-trapped/

int Solution::trap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
class Solution {
    public:
        int trap(int A[], int n) {
            int left = 0; int right = n - 1;
            int res = 0;
            int maxleft = 0, maxright = 0;
            while(left <= right){
                if(A[left] <= A[right]){
                    if(A[left] >= maxleft) maxleft = A[left];
                    else res += maxleft-A[left];
                    left++;
                }
                else{
                    if(A[right] >= maxright) maxright = A[right];
                    else res += maxright - A[right];
                    right--;
                }
            }
            return res;
        }
};
}


######## ANOTHER SOLUTION ##########


int Solution::trap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    vector<int> top(n);
    top[0] = A[0];
    top[n-1] = A[n-1];

    auto maxm = max_element(begin(A), end(A));
    auto dist = distance(A.begin(), maxm);
    //auto rdist = distance(A.end(), maxm)+n;
    int rdist;
    for(int i=n-1;i>=dist;i--)
        if(A[i]==*maxm) {
            rdist = i;
            break;
        }
    //cout << dist << " " << rdist << endl;
    
    for(int i=dist;i<=rdist;i++)
        top[i] = *maxm;
    
    for(int i=1;i<dist;i++)
        top[i] = max(top[i-1], A[i]);
    
    for(int i=n-2;i>rdist;i--)
        top[i] = max(top[i+1], A[i]);
    
    
    /*
    for(auto t: top)
        cout << t << " ";
    cout << endl;
    */
    int ans = 0;
    for(int i=0;i<n;i++)
        ans += (top[i]-A[i]);
    
    return ans;
}
