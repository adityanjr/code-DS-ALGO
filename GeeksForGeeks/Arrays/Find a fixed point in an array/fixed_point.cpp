#include <iostream>

using namespace std;

int fixed_point(int* a, int start, int end) {

    if(start>end)
        return -1;

    int mid = (start+end)/2;
    if(a[mid]==mid) return mid;

    int ans1,ans2;
    if(mid < a[mid])
        return fixed_point(a,start,mid-1);
    if(mid > a[mid])
        return fixed_point(a,mid+1,end);

}

int main() {

    int N;
    cout << "Enter the number of elements in the array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    int ans = fixed_point(a,0,N-1);
    if(ans==-1) cout << "No fixed point..." << endl; return 0;
    cout << "The fixed point is: " << ans << " at a[" << ans << "]" << endl;

}
