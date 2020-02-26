#include <iostream>
#include <vector>

using namespace std;

bool check_consecutive(int* a, int n) {

    int min=a[0],max=a[0],ind;
    for(int i=0;i<n;i++) {
        if(a[i] < min) min = a[i];
        if(a[i] > max) max = a[i];
    }

    if(max-min+1 != n) return false;

    vector<int> aux (n,-1);
    for(int i=0;i<n;i++) {
        ind = a[i]-min;
        if(aux[ind]!=-1) return false;
        else aux[ind] = 1;
    }
    return true;
}

int main () {

    int N;
    cout << "Enter an array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "Are the elements in the array consecutive?" << endl;
    (check_consecutive(a,N)) ? cout << "Yes\n" : cout << "No\n";

    ///Note: We can also change the elements in the array itself to negative values....
    ///This method would not use aux space but would not work for negative numbers...

}
