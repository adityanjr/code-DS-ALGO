#include <iostream>
#include <algorithm>

using namespace std;

void find_sum(int* a, int n, int sum) {

    sort(a,a+n);

    int temp,l,r;
    bool flag = false;
    for(int i=0;i<n;i++) {

        temp = sum - a[i];
        l=i+1; r=n-1;
        while(l < r) {
            if(a[l]+a[r]==temp) {
                cout << "The triplet is: " << a[l] << " " << a[r] << " " << a[i] << endl;
                l++; r--;
                flag = true;
                //return;
            }
            else if(a[l]+a[r]<temp) l++;
            else r--;
        }
    }
    if(!flag) cout << "No such sum" << endl;
}

int main () {

    int N,sum;
    cout << "Enter an array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "What sum are you looking for?" << endl;
    cin >> sum;

    find_sum(a,N,sum);

}
