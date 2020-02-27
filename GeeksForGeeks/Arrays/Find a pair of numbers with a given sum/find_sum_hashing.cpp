#include <iostream>
#include <vector>

using namespace std;

void find_sum(int* a, int n, int sum, int max) {

    int hashmap[max];
    for(int i=0;i<max;i++) hashmap[i] = 0;
    for(int i=0;i<n;i++) {

        if(sum-a[i] >=0 && hashmap[sum-a[i]] ==1) {
            cout << a[i] << " plus " << sum-a[i] << " equals " << sum << endl;
        }
        hashmap[a[i]] = 1;
    }

}

void neg_find_sum(int* a, int n, int sum, int max, int neg) {

    sum += -2*neg;
    max += -1*neg;
    int hashmap[max+1];
    for(int i=0;i<max+1;i++) hashmap[i] = 0;
    for(int i=0;i<n;i++) {

        if(sum-a[i] >=0 && hashmap[sum-a[i]] ==1) {
            cout << a[i]-(neg*-1) << " plus " << sum-a[i]-(neg*-1) << " equals " << sum-(-2*neg) << endl;
        }
        hashmap[a[i]] = 1;
    }

}

int main() {

    ///For negative values in the input...
    ///make everything positive by adding the absolute value of smallest negative integer to all numbers
    int N,sum,neg=0,max=0;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++) {
        cin >> a[i];
        if(a[i]<0 && a[i]<neg) neg = a[i];
        if(a[i] > max) max = a[i];
    }

    cout << "Enter a sum you want to find: " << endl;
    cin >> sum;

    ///The function works for all positve and negative numbers...
    for(int i=0;i<N;i++) a[i] += (neg*-1);
    neg_find_sum(a,N,sum,max,neg);

}
