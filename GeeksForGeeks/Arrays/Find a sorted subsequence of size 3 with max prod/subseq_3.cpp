#include <iostream>

using namespace std;

void get_subseq(int* a, int n) {

    int* smaller = new int[n];
    int* greater = new int[n];

    smaller[0] = -1;
    int min = a[0], min_ind = 0;
    for(int i=1;i<n;i++) {
        if(a[i] < min) { smaller[i] = -1; min = a[i]; min_ind = i; }
        else smaller[i] = min_ind;
    }

    greater[n-1] = -1;
    int max = a[n-1], max_ind = n-1;
    for(int i=n-2;i>=0;i--) {
        if(a[i] > max) {greater[i] = -1; max = a[i]; max_ind = i;}
        else greater[i] = max_ind;
    }

    for(int i=0;i<n;i++) {
        if(greater[i]!=-1 && smaller[i]!=-1) {
            cout << a[smaller[i]] << " " << a[i] << " " << a[greater[i]] << endl;
            return;
        }
    }

    delete smaller,greater;
    cout << "No such subsequence" << endl;

}

int main() {

    int N;
    cout << "Enter the array:" << endl;
    cin >> N;
    int* a = new int[N];

    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "The increasing subsequence of size 3 is:" << endl;
    get_subseq(a,N);

}
