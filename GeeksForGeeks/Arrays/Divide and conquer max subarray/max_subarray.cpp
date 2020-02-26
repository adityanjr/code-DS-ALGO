#include <iostream>
#include <algorithm>

using namespace std;

int max_subarray(int* a, int l, int r) {

    if(l==r)
        return a[l];

    int m = (l + r)/2;

    int s1=0,s2=0,s3=0;
    s1 = max_subarray(a,l,m);
    s2 = max_subarray(a,m+1,r);

    /// Maximum crossing subarray...
    int sum =0,lsum=a[m],rsum=a[m+1];
    for(int i=m;i>=l;i--) {
        sum += a[i];
        if(sum > lsum)
            lsum = sum;
    }
    sum=0;
    for(int i=m+1;i<=r;i++) {
        sum += a[i];
        if(sum > rsum)
            rsum = sum;
    }
    s3 = lsum + rsum;

    cout << s1 << " " << s2 << " " << s3 << endl;
    return max(max(s1,s2),s3);

}

int main() {

    int N;
    cin >> N;
    int* a = new int[N];
    for(int i =0;i<N;i++) {
        cin >> a[i];
    }

    int ans = max_subarray(a,0,N-1);
    cout << ans << endl;

}
