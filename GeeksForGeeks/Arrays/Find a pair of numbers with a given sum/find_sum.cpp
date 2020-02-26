#include <iostream>
#include <algorithm>

using namespace std;

void find_sum(int* a, int n, int sum) {

    sort(a,a+n);

    int l=0,r=n-1,flag = 0;
    while(l<r) {
        if(a[l] + a[r] == sum) {
            cout << a[l] << " plus " << a[r] << " equals " << sum << endl;
            l++;
            flag = 1;//return;
        }
        else if(a[l] + a[r] < sum)
            l++;
        else if(a[l] + a[r] > sum)
            r--;

    }

    if(flag) return;
    cout << "There are not two numbers with the sum " << sum << endl;
    return;

}

int main() {

    int N,sum;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++) {
        cin >> a[i];
    }

    cout << "Enter a sum you want to find: " << endl;
    cin >> sum;

    find_sum(a,N,sum);

}
