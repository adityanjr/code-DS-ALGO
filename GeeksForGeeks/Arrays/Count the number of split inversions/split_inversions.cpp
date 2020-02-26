#include <iostream>

using namespace std;

void rotate(int* v, int a, int b) {
    int temp = v[b];
    for(int i=b;i>=a+1;i--) {
        v[i] = v[i-1];
    }
    v[a] = temp;
}

int count_merge_inv(int* a, int low, int high) {

///This is an in-place implementation...using a scratch array works fine too...!!!
    int mid = (low+high)/2;
    int left = low,right = mid+1,c=0;
    while (left <= mid && right <= high) {
        if(a[left] <= a[right]) left++;
        else {
            rotate(a,left,right);
            left++; right++; mid++;
            c += right-left;
        }
    }
    //cout << "heyy " << c << endl;
    return c;
}

int getInvCount(int* arr, int n) {
  int inv_count = 0;
  int i, j;

  for(i = 0; i < n - 1; i++)
    for(j = i+1; j < n; j++)
      if(arr[i] > arr[j])
        inv_count++;

  return inv_count;
}

int count_split_inv(int* a, int low, int high) {

    if(low==high) return 0;

    int inv_count=0;
    int mid = (low+high)/2;
    inv_count = count_split_inv(a,low,mid);
    inv_count += count_split_inv(a,mid+1,high);
    inv_count += count_merge_inv(a,low,high);

    /*for(int i=low;i<=high;i++)
        cout << a[i] << " ";
    cout << endl;*/

    return inv_count;
}

int main() {

    int N;
    cout << "Enter an array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "Naive algo: Number of inversions are:" << endl;
    cout << getInvCount(a,N) << endl;
    cout << "The number of split inversions in the array are:" << endl;
    cout << count_split_inv(a,0,N-1) << endl;

}
