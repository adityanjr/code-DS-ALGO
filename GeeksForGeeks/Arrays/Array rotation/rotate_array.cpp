#include <iostream>

using namespace std;

int GCD(int a, int b) {

    if(b==0)
        return a;
    else
        return(b,a%b);
}

void rotate_array(int* a, int n, int rotate) {

    int gcd_sets = GCD(rotate,n);
    int temp,set,j;
    //j is the iterator that skips sets..

    for(int i=0;i<gcd_sets;i++) {
        temp = a[i];
        j = i;
        while(1) {
            set = j+gcd_sets;
            if(set-n == i) break;
            a[j] = a[set];
            j = set;
        }
        a[j] = temp;
    }
}

int main() {

    int N,rotate;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    int* a = new int[N];

    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "Enter a number to rotate by:" << endl;
    cin >> rotate;

    cout << "After rotating the array left by " << rotate << " the array is:" << endl;
    rotate_array(a,N,rotate);

    for(int i=0;i<N;i++)
        cout << a[i] << " ";
    cout << endl;

}
