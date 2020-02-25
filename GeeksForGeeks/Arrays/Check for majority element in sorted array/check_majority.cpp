#include <iostream>

using namespace std;

int bin_search(int* a, int start, int end, int num) {

    if(start > end) return -1;

    int mid = (start+end)/2;

    if(a[mid]==num && (a[mid-1]<num || mid==0)) return mid;

    if(num <= mid)
        bin_search(a,start,mid-1,num);

    else
        bin_search(a,mid+1,end,num);
}

bool majority_elem(int* a, int n, int x) {

    int start = bin_search(a,0,n-1,x);

    if(start==-1) return false;

    int end = (n%2==0) ? (n/2)-1 : n/2;
    if(a[start]==x && a[start+end]==x) return true;
    return false;

}

int main() {

    int N,num;
    cout << "Enter the array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "Enter a number to find out if it is the majority:" << endl;
    cin >> num;

    cout << "Is " << num << " a majority element?" << endl;
    (majority_elem(a,N,num)) ? cout << "Yes" << endl : cout << "No" << endl;

}
