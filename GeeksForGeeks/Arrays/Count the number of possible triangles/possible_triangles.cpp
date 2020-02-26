#include <iostream>
#include <algorithm>

using namespace std;

int find_triangles(int* a, int n) {

    /// important SORT step...!
    sort(a,a+n);

    int count = 0;
    for(int i=0;i<n-2;i++) {

        int k = i+2, p = i+2;
        for(int j=i+1;j<=n-1;j++) {

            /// the following loop is for printing only.../////////
            p  = j+1;
            while(p<n && a[p] < a[i] + a[j]) {
                if(p!=j)
                    cout << a[i] << " " << a[j] << " " << a[p] << endl;
                p++;
            }
            ///-----------------------------------------------///

            while(k<n && (a[k] < a[i] + a[j]))
                k++;

            count += k-j-1;
        }
    }
    return count;

}


int main() {

    int N;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++) {
        cin >> a[i];
    }

    int tri = find_triangles(a,N);
    cout << "The number of possible triangles: " << tri << endl;

}
