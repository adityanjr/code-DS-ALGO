#include <iostream>

using namespace std;

void product_puzzle(int* a, int n) {

    int* left_prod = new int[n];
    int* right_prod = new int[n];

    left_prod[0]=1;
    for(int i=0;i<n;i++)
        left_prod[i+1] = a[i]*left_prod[i];

    right_prod[n-1]=1;
    for(int i=n-1;i>=0;i--)
        right_prod[i-1] = a[i]*right_prod[i];

    for(int i=0;i<n;i++)
        cout << left_prod[i]*right_prod[i] << " ";
    cout << endl;
}

int main() {

    int N;
    cout << "Enter the array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];


    cout << "The product of all elements except a single element are:" << endl;
    product_puzzle(a,N);

}
