//  https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/

int Solution::maxProfit(const vector<int> &A) {
    int profit = 0;
    int n = A.size();
    for(int i=1;i<n;i++)
        profit += max(0, A[i]-A[i-1]);
    return profit;
}

