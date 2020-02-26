#include <iostream>

using namespace std;

int get_occur(int* a, int low, int high, int num, bool first, int n) {

    if(low > high) return -1;

    int mid = (low+high)/2;

    if(first) {if(a[mid]==num && (a[mid-1] < num || mid==0)) return mid; }
    if (!first) { if(a[mid]==num && (a[mid+1] > num || mid==n-1)) return mid; }

    if(first && a[mid] >= num) return get_occur(a,low,mid-1,num,first,n);
    if(!first && a[mid] > num) return get_occur(a,low,mid-1,num,first,n);
    if(!first && a[mid] <= num) return get_occur(a,mid+1,high,num,first,n);
    if(first && a[mid] < num)return get_occur(a,mid+1,high,num,first,n);

}

int count_freq(int* a, int n, int num) {

    int temp1 = get_occur(a,0,n-1,num,true,n);
    int temp2 = get_occur(a,0,n-1,num,false,n);
    //cout << temp2 << " " << temp1 << endl;
    return temp2-temp1+1;

}

int main () {

    int N,num;
    cout << "Enter a sorted array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "For which number do you want to find the occurences for?" << endl;
    cin >> num;

    cout << num << " occurs " << count_freq(a,N,num) << " time(s)..." << endl;
}
