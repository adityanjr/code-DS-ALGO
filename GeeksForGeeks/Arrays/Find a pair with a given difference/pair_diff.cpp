#include <iostream>
#include <algorithm>

using namespace std;

void find_pair_diff(int* a, int n, int d) {
    sort(a,a+n);
    int j=1;
    for(int i=0;i<n;) {
        if(a[j] - a[i] > d) {
            i++;
            j = i+1;
        }
        else if(a[j] - a[i] < d) {
            j++;
            //we reached the end and the difference is still less than what we want
            if(j==n) {cout << "No such pair" << endl; break;}
        }
        else {
            cout << a[i] << " " << a[j] << endl;
            break;
        }
    }

}

int main() {

    int N,diff;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "Enter the difference you want to find between two elements?" << endl;
    cin >> diff;


    find_pair_diff(a,N,diff);

}
