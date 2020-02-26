#include <iostream>

using namespace std;

void equilibrium_pts(int* a, int n) {

    int leftSum=0,rightSum=0;
    for(int i=0;i<n;i++)
        rightSum+=a[i];

    //cout << rightSum << " " << leftSum << endl;
    for(int i=0;i<n;i++) {
        rightSum = rightSum - a[i];
        //cout << rightSum << " " << leftSum << endl;
        if(leftSum==rightSum) {cout << "Equilibrium Index at: " << i << endl;}
        leftSum += a[i];
    }
}

int main() {

    int N;
    cout << "Enter the array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "The equilibrium points for the array are:" << endl;
    equilibrium_pts(a,N);

}
