//  https://www.interviewbit.com/problems/repeat-and-missing-number-array/



typedef long long ll;
vector<int> Solution::repeatedNumber(const vector<int> &A) {
 
   ll n = A.size();
   ll sum = 0;
   ll sum_sq = 0;
   
   for(ll i=0;i<n;i++) {
       sum += (ll)A[i];
       sum_sq += ((ll)A[i]*(ll)A[i]);
   }
   
   ll sum_ac = (n*(n+1))/2;
   ll sum_sq_ac = (n*(n+1)*(2*n+1))/6;
   
   ll diff1 = sum_ac - sum;
   ll diff2 = sum_sq_ac - sum_sq;
   
   diff2 = diff2/diff1;
   
   int missing = (diff1 + diff2)/2;
   int repeated = (diff2 - diff1)/2;
   
   vector<int> res;
   res.push_back(repeated);
   res.push_back(missing);
   return res;
}
